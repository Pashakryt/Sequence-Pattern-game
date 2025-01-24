void generator(int game1[20][40]){
    for(int y = 0; y < 20; y++){
        for(int x = 0; x < 40; x++){
            game1[y][x] = rand() % 10;
        }
    }
}
void generatingscr(const int game1[20][40], int find[6]){
    int game123[800];
    int d = 0;
    for(int w = 0; w < 20; w++){
        for(int q = 0; q < 40; q++){
            game123[d] = game1[w][q];
            d++;
        }
    }
    int rannum = rand() % 794;
    for(int z = 0; z < 6; z++){
        find[z] = game123[z+rannum];
    }

}
void game1draw(const int game1[20][40], int lines, int cols, int *x, int *y, int white[6], int *non){    
    attron(COLOR_PAIR(1));
    for(int y1 = 0; y1 < 20; y1++){
        for(int x1 = 0; x1 < 40; x1++){
            
            if(*x == x1 + cols / 2 - 20 && *y == y1 + lines / 2 - 10){
                *non = 6;
            } 
            if(*non>0){
                attroff(COLOR_PAIR(1));
                attron(COLOR_PAIR(10));
                mvprintw(y1 + lines / 2 - 10, x1 + cols / 2 - 20, "%d", game1[y1][x1]);
                attroff(COLOR_PAIR(10));
                attron(COLOR_PAIR(1));
                *non -= 1;
                white[5 - *non] = game1[y1][x1];
            }
            else{
                mvprintw(y1 + lines / 2 - 10, x1 + cols / 2 - 20, "%d", game1[y1][x1]);
            }
        }
    }
    attroff(COLOR_PAIR(1));
}
void game1work(int game12[20][40], int lines, int cols, int *x, int *y){
    int tempor = game12[19][39];
    for(int r = 19; r > 0; r--){
        for(int c = 39; c > 0; c--){
            game12[r][c] = game12[r][c-1];
        }
        game12[r][0] = game12[r-1][39];
    }
    for(int c = 39; c > 0; c--){
        game12[0][c] = game12[0][c-1];
    }
    game12[0][0] = tempor;
    
}
void moving_cursor(char c, int *x, int *y){
    
    getyx(stdscr, *y, *x);
    if(c == 'a'){
        if(*x == COLS/2 - 20){
            *x += 39;
            if(*y == LINES/2 - 10){
                *y += 19;
            }
            else{
                *y -= 1;
            }
            move(*y, *x);
        }
        else{
            *x -= 1;
            move(*y, *x);
        }
    }
    if(c == 'd'){
        if(*x == COLS/2 + 19){
            *x -= 39;
            if(*y == LINES/2 +  9){
                *y -= 19;
            }
            else{
                *y += 1;
            }
            move(*y, *x);
        }    
        else{
            *x += 1;
            move(*y, *x);
        }
    }
    if(c == 's'){
        if(*y == LINES/2 + 9){
            *y -= 19;
        }
        else{
            *y += 1;
        }
        move(*y, *x);
    }
    if(c == 'w'){
        if(*y == LINES/2 - 10){
            *y += 19;
        }
        else{
            *y -= 1;
        }
        move(*y, *x);
    }
}
int checkwin(const int *x, const int *y, const int find[6], const int white[6]){
    for(int l = 0; l < 6; l++){
        if(white[l] != find[l]){
            return 0;
        }
    }
   
    return 1;
    
    
}
void showingtime(int sec, int LINES, int COLS){
    attron(COLOR_PAIR(9));
    mvprintw(LINES/4 - 7, COLS/2 - 5, "TIME LEFT:");
    if(sec >= 10)mvprintw(LINES/4 - 6, COLS/2 -1 , "%d", sec);
    if(sec<100){
        mvprintw(LINES/4 - 6, COLS/2 - 4, "           ");
        mvprintw(LINES/4 - 6, COLS/2 - 1, "%d", sec);
    }
    attroff(COLOR_PAIR(9));
}
void timeoff(int LINES, int COLS){
    attron(COLOR_PAIR(8));
    mvprintw(LINES/4 - 8, COLS/2 - 20, "/\\/\\/\\/\\/\\/\\                /\\/\\/\\/\\/\\/\\");
    mvprintw(LINES/4 - 6, COLS/2 - 20, "\\/\\/\\/\\/\\/\\/                \\/\\/\\/\\/\\/\\/");
    attroff(COLOR_PAIR(8));
    
    
        attron(COLOR_PAIR(7));
          mvprintw(LINES/4 - 7, COLS/2 - 20, "!TIME IS OUT!               ");
        mvprintw(LINES/4 - 7, COLS/2 + 5, "  !TIME IS OUT!"); 
        attroff(COLOR_PAIR(7));
        refresh();    
}
void timeou1(int LINES, int COLS){
    attron(COLOR_PAIR(1));
        mvprintw(LINES/4 - 7, COLS/2 - 23, "                                                         ");
        attroff(COLOR_PAIR(1));
        refresh();
}
void lostgm1(char gamo, int LINES, int COLS, int winlose){
    attron(COLOR_PAIR(1));
    mvprintw(LINES/2 + 20, COLS/2 - 11, "                      ");
    refresh();
    napms(500);
    
    attroff(COLOR_PAIR(1));
    nodelay(stdscr, TRUE);
    int all = rand() % LINES; // black screen animation
    int alc = rand() % COLS;
    int repeats = 0;
    int chl = 0;
    attron(COLOR_PAIR(10));
    while(true){
            mvprintw(all, alc, " ");
            repeats++;
            if(repeats == 100){
                refresh();
                repeats = 0;
                napms(10);
                chl++;
            }
            all = rand() % LINES;
            alc = rand() % COLS;
            if(chl == 800){
                break;
            }
    }
    for(int l = 0; l < LINES; l++){
       for(int c = 0; c < COLS; c++){
            mvprintw(l, c, " ");
        }
    }
    refresh();
    napms(500);   // text end
    if(winlose == 0){
        char winning_quote[] = "THE GAME IS OVER FOR YOU";
        for(int x = 0; x < strlen(winning_quote); x++){
                mvprintw(LINES/2, COLS/2 - 12 + x, "%c", winning_quote[x]);
                refresh();
                napms(40);
        }
    }
    if(winlose == 1){
        char winning_quote[] = "YOU WON! PRESS SPACE TO PROCEED";
        for(int x = 0; x < strlen(winning_quote); x++){
            if(winning_quote[x] == '!'){
                mvprintw(LINES/2, COLS/2 - 16 + x, "%c", winning_quote[x]);
                refresh();
                napms(150);    
            }
            else{
                mvprintw(LINES/2, COLS/2 - 16 + x, "%c", winning_quote[x]);
                refresh();
                napms(40);
            }
        }
    }
    if(winlose == 0){
        napms(800);  // dots animation
        int t1 = 0;
        gamo = getch();
        while(gamo == ERR){
            napms(10);
            gamo = getch();
            t1++;
            
            if(t1 == 80){
            mvprintw(LINES/2, COLS/2 + 12, ".");
            refresh();
            }
            // napms(400);
            if(t1 == 160){
            mvprintw(LINES/2, COLS/2 + 13, ".");
            refresh();
            }
            // napms(400);
            if(t1 == 240){
            mvprintw(LINES/2, COLS/2 + 14, ".");
            refresh();
            
            }
            // napms(800);
            if(t1 == 320){
            mvprintw(LINES/2, COLS/2 + 12, "   ");
            refresh();
            t1 =0;
            }
            if(t1 == 500){
                t1 = 0;
            }    
        }
    }
    else{
        napms(800);  // dots animation
        int t1 = 0;
        gamo = getch();
        while(gamo != ' '){
            napms(10);
            gamo = getch();
            t1++;
            
            if(t1 == 80){
            mvprintw(LINES/2, COLS/2 + 15, ".");
            refresh();
            }
            // napms(400);
            if(t1 == 160){
            mvprintw(LINES/2, COLS/2 + 16, ".");
            refresh();
            }
            // napms(400);
            if(t1 == 240){
            mvprintw(LINES/2, COLS/2 + 17, ".");
            refresh();
            
            }
            // napms(800);
            if(t1 == 320){
            mvprintw(LINES/2, COLS/2 + 15, "   ");
            refresh();
            t1 =0;
            }
            if(t1 == 500){
                t1 = 0;
            }    
        }
    }
    attroff(COLOR_PAIR(10));
    
}
void beauclear(int LINES, int COLS){
    move(LINES/2, COLS/2 + 17);
    for(int k = 0; k <= 34; k++){
        attron(COLOR_PAIR(10));
        mvprintw(LINES/2, COLS/2 + 17 - k, " ");
        napms(50);
        refresh();
        attroff(COLOR_PAIR(10));
    }
}
void rules(char gamo){
    attron(COLOR_PAIR(10));
    gamo = getch();
    char row1[] = "The point of the game is to find the right sequence.";
    char row2[] = "The sequence will be shown in the upper part of the screen.";
    char row3[] = "To move use keys 'a', 'd', 's', 'w'.";
    char row4[] = "To choose the sequence press ENTER.";
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
        attroff(COLOR_PAIR(10));
}
int game1_full(int sec){
    curs_set(0);                        // no cursor
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_GREEN, COLOR_WHITE);
    init_pair(3, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(4, COLOR_CYAN, COLOR_WHITE);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    init_pair(6, COLOR_BLUE, COLOR_WHITE);
    init_pair(7, COLOR_RED, COLOR_WHITE);
    init_pair(8, COLOR_WHITE, COLOR_WHITE);
    init_pair(9, COLOR_BLACK, COLOR_WHITE);
    init_pair(10, COLOR_WHITE, COLOR_BLACK);
                  
    noecho();                           // no writings
    srand(time(NULL));
    int game1[20][40];                  // initializing two 2darrays
    int game12[20][40];
    int find[6];
    int white[6];
    char gamo = 'a';
    nodelay(stdscr, TRUE); // no delay
    rules(gamo);
    
    getch();
    clear();
    

                  
    generator(game1);                   // generating
    attron(COLOR_PAIR(9));
    for(int q = 0; q < LINES; q++){
        for(int w = 0; w < COLS; w++){
            mvprintw(q, w, " ");
        }
    }
    attroff(COLOR_PAIR(9));             
    attron(COLOR_PAIR(2));
    mvprintw(LINES/4 - 3, COLS/2 - 8, "SECRET SEQUENCE:");
    attroff(COLOR_PAIR(2));
    generatingscr(game1, find);
    attron(COLOR_PAIR(3));
    for(int s = 0; s < 6; s++){         // prints the secret
        mvprintw(LINES/4 - 2, COLS/2 - 3 + s, "%d", find[s]);
    }    
    attroff(COLOR_PAIR(3));
    
    attron(COLOR_PAIR(4));
    mvprintw(LINES/2 + 20, COLS/2 - 10, "TO EXIT PRESS ESC...");
    attroff(COLOR_PAIR(4));
    int x = COLS/2, y = LINES/2;
    int nono = 0;
    game1draw(game1, LINES, COLS, &x, &y, white, &nono); // first print
    refresh();

    for(int y = 0; y < 20; y++){        // copying arrays
        for(int x = 0; x < 40; x++){
            game12[y][x] = game1[y][x];
        }
    }// initializing some variables for future game         
        gamo = getch();
        int repeats = 1;
        //int sec = 120;
        
    do{
        repeats +=1;
        napms(10);
        if(repeats == 100){ // seconds function use here
            game1work(game12, LINES, COLS, &x, &y);
            repeats = 1;
            sec-=1;
            if(sec == -1){
                curs_set(0);
                int x =0;
                while(x < 20){
                    napms(100);
                    timeoff(LINES, COLS);
                    refresh();
                    napms(100);
                    timeou1(LINES, COLS);
                    refresh();
                    x++;
                }
                attron(COLOR_PAIR(1));
                mvprintw(LINES/4 - 8, COLS/2 - 20, "                                                    ");
                mvprintw(LINES/4 - 6, COLS/2 - 20, "                                                    ");
                attroff(COLOR_PAIR(1));
                nodelay(stdscr, FALSE);
                lostgm1(gamo, LINES, COLS, 0);
                beauclear(LINES, COLS);
                napms(1000);
                return 0;
                break;          
            }

        }
        game1draw(game12, LINES, COLS, &x, &y, white, &nono); 
        refresh();
        showingtime(sec, LINES, COLS);
        gamo = getch();
        move(y, x);
        moving_cursor(gamo, &x, &y);
        if(gamo == '\n' && checkwin(&x , &y, find, white) == 1){
            nodelay(stdscr, FALSE);
            lostgm1(gamo, LINES, COLS, 1);
            beauclear(LINES, COLS);
            return 1;
            break;
        }
        refresh();
    }while(gamo != 27);
    return 3;
}