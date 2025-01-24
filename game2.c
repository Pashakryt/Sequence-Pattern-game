void generator2(int cube[5][5]){
    for(int q = 0; q < 5; q++){
        for(int f = 0; f <5; f++){
            cube[q][f] = 0;
        }
        int w = rand() % 5;
        cube[q][w] = 1;
    }
}
void allblack(int LINES, int COLS){
    attron(COLOR_PAIR(8));
    for(int l = 0; l < LINES; l++){
       for(int c = 0; c < COLS; c++){
            mvprintw(l, c, " ");
        }
    }
    attroff(COLOR_PAIR(8));
    refresh();
}
void draw2(const int cube[5][5], int LINES, int COLS){
    attron(COLOR_PAIR(7));
     //horizontal lines
    for(int l = 0; l < 12; l++){               
        mvprintw(LINES/2 - 6, COLS/2 + l*2 -12, "  ");
        refresh();     
        napms(80);
    }
     // vertical lines
    for(int l = 0; l < 5; l++){
        mvprintw(LINES/2 + l*2 - 5, COLS/2 +10, "  ");
        refresh();
        napms(80);
        mvprintw(LINES/2 + l*2 - 4, COLS/2 +10, "  ");
        refresh(); 
        napms(80);
    }  
    //horizontal lines
    for(int l = 11; l >= 0; l--){               
        mvprintw(LINES/2 - 6 + 11, COLS/2 + l*2 -12, "  ");
        refresh();     
        napms(80);
    }      
     // vertical lines
    for(int l = 4; l >= 0; l--){                      
        mvprintw(LINES/2 + l*2 - 4, COLS/2 -12, "  ");
        refresh(); 
        napms(80);
        mvprintw(LINES/2 + l*2 - 5, COLS/2 -12, "  ");
        refresh();
        napms(80);
    }
    napms(1500);
    for(int l = 0; l < 5; l++){  // random cubes
        for(int r = 0; r < 5; r++){
            if(cube[l][r] == 1){
                attron(COLOR_PAIR(6));
                mvprintw(LINES/2 + l*2 - 5, COLS/2 + r*4 -10, "    ");
                mvprintw(LINES/2 + l*2 - 4, COLS/2 + r*4 -10, "    ");
                attroff(COLOR_PAIR(6));
                refresh();
                napms(900);
                attron(COLOR_PAIR(8));
                mvprintw(LINES/2 + l*2 - 5, COLS/2 + r*4 -10, "    ");
                mvprintw(LINES/2 + l*2 - 4, COLS/2 + r*4 -10, "    ");
                attroff(COLOR_PAIR(8));
                refresh();
                napms(900);
                
            }
        }
    }
    refresh();
    attroff(COLOR_PAIR(7));
}
void showing_cursor(int **x, int **y, int **xr, int **yr, int **color){
    **color = mvinch(**y, **x) & A_COLOR;
    attron(COLOR_PAIR(5));
    mvprintw(**y, **x, "    ");
    mvprintw(**y - 1, **x, "    ");
    attroff(COLOR_PAIR(5));
    move(**y, **x);
    refresh();
    **xr = **x;
    **yr = **y;
    //black 2048
    //red 1536
    //green 2304
    
}
void showing_cursorfirst(int *x, int *y, int *xr, int *yr, int *color){
    *color = mvinch(*y, *x) & A_COLOR;
    attron(COLOR_PAIR(5));
    mvprintw(*y, *x, "    ");
    mvprintw(*y - 1, *x, "    ");
    attroff(COLOR_PAIR(5));
    move(*y, *x);
    refresh();
    *xr = *x;
    *yr = *y;
    //black 2048
    //red 1536
    //green 2304
    
}
void returning_color(int **x, int **y, int **xr, int **yr, int **color){
    if(**color == 2048){
        attron(COLOR_PAIR(8));
        mvprintw(**yr, **xr, "    ");
        mvprintw(**yr - 1, **xr, "    ");
        attroff(COLOR_PAIR(8));
        move(**y, **x);
        refresh();
    }
    if(**color == 1536){
        attron(COLOR_PAIR(6));
        mvprintw(**yr, **xr, "    ");
        mvprintw(**yr - 1, **xr, "    ");
        attroff(COLOR_PAIR(6));
        move(**y, **x);
        refresh();
    }
    if(**color == 2304){
        attron(COLOR_PAIR(9));
        mvprintw(**yr, **xr, "    ");
        mvprintw(**yr - 1, **xr, "    ");
        attroff(COLOR_PAIR(9));
        move(**y, **x);
        refresh();
    }
}
void moving_cursor1(const char c, int *x, int *y, int *xr, int *yr, int *color){
    getyx(stdscr, *y, *x);
    if(c == 'a'){       
        if(*x > COLS/2 - 10){
            returning_color(&x, &y, &xr, &yr, &color);
            *x -= 4;
            move(*y, *x);    
            showing_cursor(&x, &y, &xr, &yr, &color); 
        }
    }
    if(c == 'd'){
        if(*x < COLS/2 + 6){
            returning_color(&x, &y, &xr, &yr, &color);
            *x += 4;
            move(*y, *x);
            showing_cursor(&x, &y, &xr, &yr, &color);
        } 
    }

    if(c == 's'){
        if(*y < LINES/2 + 4){
            returning_color(&x, &y, &xr, &yr, &color);
            *y += 2;
            move(*y, *x);
            showing_cursor(&x, &y, &xr, &yr, &color);
        }
    }
    if(c == 'w'){
        if(*y > LINES/2 - 4){
            returning_color(&x, &y, &xr, &yr, &color);
            *y -= 2;
            move(*y, *x);
            showing_cursor(&x, &y, &xr, &yr, &color);
        }
    }
} 
void check(int *x, int *y, const int cube[5][5], int *tries, int *right, int *xr, int *yr, int *color){
    getyx(stdscr, *y, *x);
    int x12 = *x;
    int y12 = *y;
    for(int ye = 0; ye < 5; ye++){
        for(int xe = 0; xe < 5; xe++){
            if((*y == LINES/2 + ye*2 - 4) && (*x == COLS/2 + xe*4 -10)){
                if(cube[ye][xe] == 1){
                    
                    attron(COLOR_PAIR(9));
                    mvprintw(LINES/2 + ye*2 - 5, COLS/2 + xe*4 -10, "    ");
                    mvprintw(LINES/2 + ye*2 - 4, COLS/2 + xe*4 -10, "    ");
                    attroff(COLOR_PAIR(9));
                    refresh();
                    *right +=1;
                    
                }
                else if(cube[ye][xe] == 0){
                    
                    attron(COLOR_PAIR(6));
                    mvprintw(LINES/2 + ye*2 - 5, COLS/2 + xe*4 -10, "    ");
                    mvprintw(LINES/2 + ye*2 - 4, COLS/2 + xe*4 -10, "    ");
                    attroff(COLOR_PAIR(6));
                    refresh();
                    *tries -= 1;
                    
                }
            }
        }
    }
    showing_cursor(&x, &y, &xr, &yr, &color);
    move(y12, x12);
}
void win(int LINES, int COLS){
    attron(COLOR_PAIR(8));
    for(int l = 0; l < 5; l++){  // random cubes      
        mvprintw(LINES/2 + l*2 - 5, COLS/2 - 10, "                    ");
        mvprintw(LINES/2 + l*2 - 4, COLS/2 - 10, "                    ");
                    
    }
    refresh();
    
    napms(2000);
     //horizontal lines
    for(int l = 1; l < 12; l++){               
        mvprintw(LINES/2 - 6, COLS/2 + l*2 -12, "  ");
        refresh();     
        napms(100);
    }
     // vertical lines
    for(int l = 0; l < 5; l++){
        mvprintw(LINES/2 + l*2 - 5, COLS/2 +10, "  ");
        refresh();
        napms(100);
        mvprintw(LINES/2 + l*2 - 4, COLS/2 +10, "  ");
        refresh(); 
        napms(100);
    }  
        
    //horizontal lines
    for(int l = 11; l >= 0; l--){               
        mvprintw(LINES/2 - 6 + 11, COLS/2 + l*2 -12, "  ");
        refresh();     
        napms(100);
    }      
     // vertical lines
    for(int l = 4; l >= 0; l--){                      
        mvprintw(LINES/2 + l*2 - 4, COLS/2 -12, "  ");
        refresh(); 
        napms(100);
        mvprintw(LINES/2 + l*2 - 5, COLS/2 -12, "  ");
        refresh();
        napms(100);
    }
    napms(1000);
    char winner[] = "YOU WON!";
    for(int w = 0; w < strlen(winner); w++){
        mvprintw(LINES/2 - 6, COLS/2 -9 + w, "%c", winner[w]);
        refresh();
        napms(150);
    }
    attroff(COLOR_PAIR(8));
    napms(2000);
}
void lose(int LINES, int COLS){
    attron(COLOR_PAIR(8));
    for(int l = 0; l < 5; l++){  // random cubes      
        mvprintw(LINES/2 + l*2 - 5, COLS/2 - 10, "                    ");
        mvprintw(LINES/2 + l*2 - 4, COLS/2 - 10, "                    ");
                    
    }
     refresh();
     
    napms(2000);
     //horizontal lines
    for(int l = 1; l < 12; l++){               
        mvprintw(LINES/2 - 6, COLS/2 + l*2 -12, "  ");
        refresh();     
        napms(100);
    }
     // vertical lines
    for(int l = 0; l < 5; l++){
        mvprintw(LINES/2 + l*2 - 5, COLS/2 +10, "  ");
        refresh();
        napms(100);
        mvprintw(LINES/2 + l*2 - 4, COLS/2 +10, "  ");
        refresh(); 
        napms(100);
    }  
        
    //horizontal lines
    for(int l = 11; l >= 0; l--){               
        mvprintw(LINES/2 - 6 + 11, COLS/2 + l*2 -12, "  ");
        refresh();     
        napms(100);
    }      
     // vertical lines
    for(int l = 4; l >= 0; l--){                      
        mvprintw(LINES/2 + l*2 - 4, COLS/2 -12, "  ");
        refresh(); 
        napms(100);
        mvprintw(LINES/2 + l*2 - 5, COLS/2 -12, "  ");
        refresh();
        napms(100);
    }
    napms(1000);
     char winner[] = "YOU LOST";
    for(int w = 0; w < strlen(winner); w++){
        mvprintw(LINES/2 - 6, COLS/2 -9 + w, "%c", winner[w]);
        refresh();
        napms(150);
    }
    attroff(COLOR_PAIR(8));
    napms(2000);
}
void rules2(char gamo){
    attron(COLOR_PAIR(8));
    gamo = getch();
    char row1[] = "The point of the game is to remember the shown cubes.";
    char row2[] = "The cubes will be shown with time.";
    char row3[] = "To move use keys 'a', 'd', 's', 'w'.";
    char row4[] = "To choose the cube press ENTER. You have only 3 wrong tries.";
    char row5[] = "To proceed press anything";
    for(int c = 0; c < strlen(row1); c++){
        mvprintw(1, 1 + c, "%c", row1[c]);
        refresh();
        napms(40);
    }
    napms(1500);
    for(int c = 0; c < strlen(row2); c++){
        mvprintw(2, 1 + c, "%c", row2[c]);
        refresh();
        napms(40);
    }
    napms(1500);
    for(int c = 0; c < strlen(row3); c++){
        mvprintw(3, 1 + c, "%c", row3[c]);
        refresh();
        napms(40);
    }
    napms(1500);
    for(int c = 0; c < strlen(row4); c++){
        mvprintw(4, 1 + c, "%c", row4[c]);
        refresh();
        napms(40);
    }
    napms(2000);
    for(int c = 0; c < strlen(row5); c++){
        mvprintw(5, 1 + c, "%c", row5[c]);
        refresh();
        napms(40);
    }
    napms(800);  // dots animation
        int t1 = 0;
        while(gamo == ERR){
            napms(10);
            gamo = getch();
            t1++;
            
            if(t1 == 80){
            mvprintw(5, 26, ".");
            refresh();
            }
            // napms(400);
            if(t1 == 160){
            mvprintw(5, 27, ".");
            refresh();
            }
            // napms(400);
            if(t1 == 240){
            mvprintw(5, 28, ".");
            refresh();
            
            }
            // napms(800);
            if(t1 == 320){
            mvprintw(5, 29, "   ");
            refresh();
            t1 =0;
            }
            if(t1 == 500){
                t1 = 0;
            }    
        }
        attroff(COLOR_PAIR(8));
}
int game2_full(){

    
    curs_set(0); 
    noecho();                       //cursor
    nodelay(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE); // colors
    init_pair(2, COLOR_WHITE, COLOR_GREEN);
    init_pair(3, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(4, COLOR_CYAN, COLOR_WHITE);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    init_pair(6, COLOR_WHITE, COLOR_RED);
    init_pair(7, COLOR_WHITE, COLOR_WHITE);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);
    init_pair(9, COLOR_WHITE, COLOR_GREEN);
    srand(time(NULL));                      //rand
    int cube[5][5];  // intializing variables
    char gamo = getch();
    int x = COLS/2, y = LINES/2;
    int tries = 3;//3
    int right = 0; //0
    int color = 2048;
    //attron(COLOR_PAIR(8));
    rules2(gamo);
    //attroff(COLOR_PAIR(8));
    clear();
    napms(800);
    
    generator2(cube);
    allblack(LINES, COLS);
    draw2(cube, LINES, COLS);
    move(LINES/2 - 4, COLS/2 -10);
    gamo = getch();
    x = COLS/2 -10;
    y = LINES/2 - 4;
    int xr, yr;
    xr = x;
    yr = y;
    showing_cursorfirst(&x, &y, &xr, &yr, &color);
    do{
        napms(10);
        gamo = getch();        
        moving_cursor1(gamo, &x, &y, &xr, &yr, &color);
        if(gamo == '\n'){
            int calar = mvinch(y, x) & A_COLOR;
            if( calar == 1280){
                check(&x, &y, cube, &tries, &right, &xr, &yr, &color);
            }
        }
        if(tries == 0){
            napms(1000);
            lose(LINES, COLS);
            return 0;
            break;
        }
        if(right == 5){
            napms(1000);
            win(LINES, COLS);
            return 1;
            break;
        }
        //repeats++;
    }while(gamo != 27);
return 3;
}