/*
 *   stuntmachine presents
 *       mmmm    mmm   m mm    mmmm 
 *       #" "#  #" "#  #"  #  #" "# 
 *       #   #  #   #  #   #  #   # 
 *       ##m#"  "#m#"  #   #  "#m"# 
 *       #                     m  # 
 *       "                     m  #  
 *       "                      ""
 */

#include <curses.h>

#define BALLSPEED 100000               /* ball speed in ms, higher is slower */

/* Begin function definitions */

int printmaintitle();
int cleanup_before_exit();

/******************************/

int printmaintitle()
{
    int i = 0;                         /* counter */
    int x = 1;                         /* start x-coordinate */
    int y = 1;                         /* start y-coordinate */
    int resx;
    int resy;
    
    int didhitbottom;
    int didhittop;
    int didhitleft;
    int didhitright;

    initscr();
    getmaxyx(stdscr, resx, resy);
    erase();
    endwin();

    srand(time(NULL));                 /* Seed the random number with time */
    
    x = resx - (rand() % resx + 1);    /* Set random ball start x-coordinate */
    y = resy - (rand() % resy + 1);    /* Set random ball start y-coordinate */

    for(i = 0; x < resx; i++)
    {
        initscr();
        curs_set(0);
        
        if (x == 1)
        {
            didhitleft = 1;
        } else if (x == resx) {
            didhitright = 1;
        } else {
            didhitleft = 0;
            didhitright = 0;
        }

        if (y == 1)
        {
            didhittop = 1;
        } else if (y == resy) {
            didhitbottom = 1;
        } else {
            didhittop = 0;
            didhitbottom = 0;
        }

        if (didhitleft = 0 || x < resx - 1 || y < resy - 1)
        {
            x--;
            y--;
        } else if (didhitleft = 1 || x < resx - 1) {
            x++;
            y++;
        }

        mvaddstr(x, y, "*");
        refresh();
        usleep(BALLSPEED);
        erase();
    }


    return 0;
}

int cleanup_before_exit()
{
    endwin();
    return 0;
}

int main(int argc, char *argv[])
{
    gameloop();
    return 0;
}

int gameloop()
{
    printmaintitle();
    cleanup_before_exit();
    return 0;
}
