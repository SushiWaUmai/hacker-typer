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

void setup_colors(void) {
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

void update_char(int current, const char *code, WINDOW *win) {
  box(stdscr, 0, 0);

  wmove(win, 0, 0);
  wprintw(win, "%.*s", current, code);

  refresh();
  wrefresh(win);
}

int main(void) {
  initscr();

  cbreak();
  noecho();

  setup_colors();

  const char *code[CODE_SNIPPETS] = {
      drw_c,           SvgLoadingContext_cpp, social_graph_snippets_py,
      TimerManager_cs, commandHandler_ts,     helloworld_asm};

  unsigned long code_lengths[CODE_SNIPPETS];

  for (int i = 0; i < CODE_SNIPPETS; i++) {
    code_lengths[i] = strlen(code[i]);
  }

  // get number of lines and cols
  int lines, cols;
  getmaxyx(stdscr, lines, cols);

  WINDOW *win = newwin(lines - 2, cols - 2, 1, 1);
  scrollok(win, TRUE);

  srand(time(NULL));

  unsigned long current_char;
  int snippet_index;
  int color_index;

  while (1) {
    // randomly select a snippet from the code
    current_char = 0;
    snippet_index = rand() % CODE_SNIPPETS;
    color_index = rand() % COLOR_COUNT + 1;

    wbkgd(stdscr, COLOR_PAIR(color_index));
    wbkgd(win, COLOR_PAIR(color_index));

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
