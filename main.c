#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void f();
void board(char b[3][3]);
int sw(int c, char b[3][3], char xo, int a);
int win(char b[3][3], char xo);
int ch(char b[3][3], char xo);

int main()
{
    int p;
	char b[3][3], xo=' ';
	int i, c, m=0, j, x, y, a=0, r, rc[9]={0, 1, 2, 10, 11, 12, 20, 21, 22};
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			b[j][i]=' ';
		}
	}
	printf("Choose game mode:\n1. Single player\n2.  Two players\n");
    if (scanf("%d", &p)!=1) {f(); return 0;}
    switch (p) {
        case 2:
        	    while (1) {
	        board(b);
	        if (win(b, xo)==1) {printf("O wins!"); return 0;}
	        m++;
	        xo='X';
	        printf("X's turn. Enter position (xy)");
	        do {
	        if (scanf("%d", &c)!=1) {f(); return 0;}
	        }
	        while (sw(c,b,xo,a)!=0);
	        board(b);
	        m++;
	        if (win(b, xo)==0) {printf("X wins!"); return 0;}
	        if (m>9) {break;}
	        xo='O';
	        printf("O's turn. Enter position (xy)");
	        do {
	        if (scanf("%d", &c)!=1) {f(); return 0;}
	        }
	        while (sw(c,b,xo,a)!=0);
	    }
        break;
        case 1:
        srand(time(0));
              while (1) {
            board(b);
            if (win(b,xo)==1) {printf("O wins!"); return 0;}
	        m++;
	        xo='X';
	        a=0;
	        printf("Your turn. Enter position (xy)\n");
	        do {
	        if (scanf("%d", &c)!=1) {f(); return 0;}
	        }
	        while (sw(c,b,xo,a)!=0);
	        board(b);
	        m++;
	        if (win(b,xo)==0) {printf("X wins!"); return 0;}
	        if (m>9) {break;}
	        xo='O';
	        if (ch(b,xo)!=1) {xo='X'; if (ch(b,xo)!=1) {xo='O';
	        a=1;
	        do {
            r=rand()%9;
            c=rc[r];
	        }
	        while (sw(c,b,xo,a)!=0);
	        }
	        else {xo='O';}
            }
            printf("\nComputer's turn:\n\n");
            }
        break;
        default: printf("invalid"); return 0;
    }
	    printf("Draw.");
	return 0;
}

void board(char b[3][3]) {
	for (int i=0; i<3; i++) {
		printf(" %c | %c | %c \n",b[i][0],b[i][1],b[i][2]);
		if (i<2) printf("-----------\n");
	}
}
int sw(int c, char b[3][3], char xo, int a) {
    int x;
    int y;
    x=c%10;
    y=c/10;
 if ((x>-1 && x<3)&&(y>-1 && y<3)) {if (b[x][y]==' ') {b[x][y]=xo; return 0;} else {if (a==0){f();} return 1;}} else {f(); return 1;}
}
void f() { printf("invalid\n"); }
int win(char b[3][3], char xo) {
int i;
for (i=0; i<3; i++) {
    if (b[i][0]==xo && b[i][1]==xo && b[i][2]==xo) {if (xo=='X') {return 0;} else if (xo=='O') {return 1;}}
    if (b[0][i]==xo && b[1][i]==xo && b[2][i]==xo) {if (xo=='X') {return 0;} else if (xo=='O') {return 1;}}
}
    if (b[0][0]==xo && b[1][1]==xo && b[2][2]==xo) {if (xo=='X') {return 0;} else if (xo=='O') {return 1;}}
    if (b[2][0]==xo && b[1][1]==xo && b[0][2]==xo) {if (xo=='X') {return 0;} else if (xo=='O') {return 1;}}
    return -1;
}

int ch(char b[3][3], char xo) {
    int i;
    for (i=0; i<3; i++) {
        if (b[i][0]==xo && b[i][1]==xo && b[i][2]==' ') {b[i][2]='O'; return 1;}
        if (b[i][0]==xo && b[i][1]==' ' && b[i][2]==xo) {b[i][1]='O'; return 1;}
        if (b[i][0]==' ' && b[i][1]==xo && b[i][2]==xo) {b[i][0]='O'; return 1;}
        if (b[0][i]==xo && b[1][i]==xo && b[2][i]==' ') {b[2][i]='O'; return 1;}
        if (b[0][i]==xo && b[1][i]==' ' && b[2][i]==xo) {b[1][i]='O'; return 1;}
        if (b[0][i]==' ' && b[1][i]==xo && b[2][i]==xo) {b[0][i]='O'; return 1;}
    }
    if (b[0][0]==xo && b[1][1]==xo && b[2][2]==' ') {b[2][2]='O'; return 1;}
    if (b[0][0]==xo && b[1][1]==' ' && b[2][2]==xo) {b[1][1]='O'; return 1;}
    if (b[0][0]==' ' && b[1][1]==xo && b[2][2]==xo) {b[0][0]='O'; return 1;}
    if (b[2][0]==xo && b[1][1]==xo && b[0][2]==' ') {b[0][2]='O'; return 1;}
    if (b[2][0]==xo && b[1][1]==' ' && b[0][2]==xo) {b[1][1]='O'; return 1;}
    if (b[2][0]==' ' && b[1][1]==xo && b[0][2]==xo) {b[2][0]='O'; return 1;}
    return 0;
}
