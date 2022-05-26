#include "code/SvgLoadingContext.h"
#include "code/TimerManager.h"
#include "code/commandHandler.h"
#include "code/drw.h"
#include "code/helloworld.h"
#include "code/social_graph_snippets.h"
#include <curses.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CODE_SNIPPETS 6
#define COLOR_COUNT 6
#define TYPE_SPEED 10

char *read_file(char *file_path) {
  FILE *file = fopen(file_path, "r");

  if (!file)
    return NULL;

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *buffer = malloc(sizeof(char) * (file_size + 1));
  fread(buffer, sizeof(char), file_size, file);
  buffer[file_size] = '\0';

  fclose(file);

  return buffer;
}

void setup_curses(void) {
  initscr();

  cbreak();
  noecho();

  if (can_change_color()) {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    refresh();
  }
}

WINDOW *create_window(void) {
  // get number of lines and cols
  int lines, cols;
  getmaxyx(stdscr, lines, cols);

  WINDOW *win = newwin(lines - 2, cols - 2, 1, 1);
  scrollok(win, TRUE);

  return win;
}

void random_color(WINDOW *win) {
  int color_index = rand() % COLOR_COUNT + 1;
  wbkgd(stdscr, COLOR_PAIR(color_index));
  wbkgd(win, COLOR_PAIR(color_index));
}

void update_char(int current, const char *code, WINDOW *win) {
  box(stdscr, 0, 0);

  wmove(win, 0, 0);
  wprintw(win, "%.*s", current, code);

  refresh();
  wrefresh(win);
}

int main(int argc, char *argv[]) {
  unsigned long current_char;
  srand(time(NULL));

  if (argc > 1) {
    char *code = read_file(argv[1]);
    if (!code) {
      fprintf(stderr, "[ERROR] Could not read file %s\n", argv[1]);
      return 1;
    }

    setup_curses();

    WINDOW *win = create_window();
    unsigned long code_len = strlen(code);
    random_color(win);

    while (1) {
      getch();
      current_char += TYPE_SPEED;
      update_char(current_char, code, win);

      if (current_char >= code_len) {
        break;
      }
    }

    return 0;
  }

  setup_curses();
  WINDOW *win = create_window();

  const char *code[CODE_SNIPPETS] = {
      drw_c,           SvgLoadingContext_cpp, social_graph_snippets_py,
      TimerManager_cs, commandHandler_ts,     helloworld_asm};

  unsigned long code_lengths[CODE_SNIPPETS];

  for (int i = 0; i < CODE_SNIPPETS; i++) {
    code_lengths[i] = strlen(code[i]);
  }

  int snippet_index;

  while (1) {
    current_char = 0;
    random_color(win);

    // randomly select a snippet from the code
    snippet_index = rand() % CODE_SNIPPETS;

    while (1) {
      getch();
      current_char += TYPE_SPEED;
      update_char(current_char, code[snippet_index], win);

      if (current_char >= code_lengths[snippet_index]) {
        break;
      }
    }
  }

  endwin();
  return 0;
}
