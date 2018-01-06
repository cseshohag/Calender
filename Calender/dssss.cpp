#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<bits/stdc++.h>
#define BGC  1 /* blue  */
#define FGC 15 /* white */

void menu(int x, int bgc, int fgc) {

	gotoxy((80 - strlen(" option 1 ")) / 2, 12);
	textbackground(x == 12 ? bgc : fgc);
	textcolor(x == 12 ? fgc : bgc); cprintf(" option 1 ");

	gotoxy((80 - strlen(" option 2 ")) / 2, 13);
	textbackground(x == 13 ? bgc : fgc);
	textcolor(x == 13 ? fgc : bgc); cprintf(" option 2 ");

	gotoxy((80 - strlen(" option 3 ")) / 2, 14);
	textbackground(x == 14 ? bgc : fgc);
	textcolor(x == 14 ? fgc : bgc); cprintf(" option 3 ");
}

int main(void) {

	int ch, ch2, cx = 12;

	_setcursortype(_NOCURSOR);
	menu(cx, BGC, FGC);

	do {
		ch = getch();
		switch(ch) {
			case 0 : ch2 = getch(); /* 72 up; 80 down */
						switch(ch2) {
							case 72 : if(cx <= 12) { cx = 14; } else { cx--; }
										 break;
							case 80 : if(cx >= 14) { cx = 12; } else { cx++; }
										 break;
						}

						menu(cx, BGC, FGC);
						break;

			case 13 : /* cx = menu target */
						 break;
		}
	} while(ch != 'q');

	_setcursortype(_NORMALCURSOR);
	return 0;
}
