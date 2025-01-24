#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>
#include "game1.c"
#include "game2.c"

void youwon(int LINES, int COLS){
// __   _____  _   _  __        _____  _   _ 
// \ \ / / _ \| | | | \ \      / / _ \| \ | |
//  \ V / | | | | | |  \ \ /\ / / | | |  \| |
//   | || |_| | |_| |   \ V  V /| |_| | |\  |
//   |_| \___/ \___/     \_/\_/  \___/|_| \_|
                                             
// __   _____  _   _   _     ___  ____ _____ 
// \ \ / / _ \| | | | | |   / _ \/ ___|_   _|
//  \ V / | | | | | | | |  | | | \___ \ | |  
//   | || |_| | |_| | | |__| |_| |___) || |  
//   |_| \___/ \___/  |_____\___/|____/ |_|  

char won[][67] = {
    "  ____    _    __  __ _____   ___ ____     _____     _______ ____  ",
    " / ___|  / \\  |  \\/  | ____| |_ _/ ___|   / _ \\ \\   / / ____|  _ \\ ",
    "| |  _  / _ \\ | |\\/| |  _|    | |\\___ \\  | | | \\ \\ / /|  _| | |_) |",
    "| |_| |/ ___ \\| |  | | |___   | | ___) | | |_| |\\ V / | |___|  _ < ",
    " \\____/_/   \\_\\_|  |_|_____| |___|____/   \\___/  \\_/  |_____|_| \\_\\"
};
for(int l = 0; l < 67; l++){
    for(int r = 0; r < 5; r++){
        mvprintw(LINES/2 - 3 + r, COLS/2 - 34 + l, "%c", won[r][l]);
        
    }
    refresh();     
    napms(40);
}

}
int main(int argc, char *argv[]){
    initscr(); // start
    if(argc >= 2){
        if(atoi(argv[1]) == 1){
            switch (argc - 1)
            {
            case 1:
                if(game1_full(60)==1){
                    clear();
                    youwon(LINES, COLS);
                    napms(5000);
                }
                else{
                    clear();
                    youwon(LINES, COLS);
                    napms(5000);
                }
                break;
            case 2:
                if(game1_full(atoi(argv[2]))==1){
                    clear();
                    youwon(LINES, COLS);
                    napms(5000);
                }
                else{
                    clear();
                    youwon(LINES, COLS);
                    napms(5000);
                }
                break;
            }
        }
        else if(atoi(argv[1]) == 2){
            if(game2_full() == 1){
                    clear();
                    youwon(LINES, COLS);
                    napms(5000);
                }
                else{
                    clear();
                    youwon(LINES, COLS);
                    napms(5000);
                }
        }
        else if(atoi(argv[1]) == 3){
            if(argc-1==2){
                if(game1_full(atoi(argv[2])) == 1){
                    clear();   
                    getch();
                    napms(2000);
                    if(game2_full() == 1){
                        clear();
                        youwon(LINES, COLS);
                        napms(5000);
                    }
                    else{
                        clear();
                        youwon(LINES, COLS);
                        napms(5000);
                    }
                }
            }
            else{
                if(game1_full(60) == 1){
                    clear();   
                    getch();
                    napms(2000);
                    if(game2_full() == 1){
                        clear();
                        youwon(LINES, COLS);
                        napms(5000);
                    }
                    else{
                        clear();
                        youwon(LINES, COLS);
                        napms(5000);
                    }
                }
            }
            
        }
        
    }
    

    endwin();
    return 0;
}

