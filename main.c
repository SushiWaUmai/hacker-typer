#include "code/TimerManager.h"
#include "code/commandHandler.h"
#include "code/drw.h"
#include "code/social_graph_snippets.h"
#include "code/SvgLoadingContext.h"
#include "code/helloworld.h"
#include <curses.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CODE_SNIPPETS 6
#define TYPE_SPEED 5

void setup_colors(void) {
  if (can_change_color()) {
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    wbkgd(stdscr, COLOR_PAIR(1));
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

  const char *code[CODE_SNIPPETS] = {drw_c, SvgLoadingContext_cpp,
                                     social_graph_snippets_py, TimerManager_cs,
                                     commandHandler_ts, helloworld_asm};

  int current_char = 0;

  // get number of lines and cols
  int lines, cols;
  getmaxyx(stdscr, lines, cols);

  WINDOW *win = newwin(lines - 2, cols - 2, 1, 1);
  scrollok(win, TRUE);
  wbkgd(win, COLOR_PAIR(1));

  srand(time(NULL));

  while (1) {
    // randomly select a snippet from the code
    int snippet_index = rand() % CODE_SNIPPETS;

    while (1) {
      while (getch() != ERR) {
        for (int i = 0; i < TYPE_SPEED; i++) {
          current_char++;
          update_char(current_char, code[snippet_index], win);
        }
      }
    }
  }

  endwin();
  return 0;
}
