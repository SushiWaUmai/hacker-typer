#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

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

void setup_colors(void) {
  if (can_change_color()) {
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    wbkgd(stdscr, COLOR_PAIR(1));
    refresh();
  }
}

void update_char(int current, char *code, WINDOW *win) {
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

  char *code = read_file("./code/drw.c");

  int current_char = 0;

  // get number of lines and cols
  int lines, cols;
  getmaxyx(stdscr, lines, cols);

  WINDOW *win = newwin(lines - 2, cols - 2, 1, 1);
  scrollok(win, TRUE);
  wbkgd(win, COLOR_PAIR(1));

  while (1) {
    getch();

    current_char++;
    update_char(current_char, code, win);
  }

  endwin();
  return 0;
}
