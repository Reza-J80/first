#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#pragma warning(disable:4996)
//some changes
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main() 
{
	char text[40][100];
	printf("                                                    editor\n");
	char  temp;
	int running = 1;
	int i = 0, j = 0;
	int x1 = 0, y1 = 0;
	while (true) {
		temp = getch();
		if (temp == -32) 
		{
			temp = getch();
			if (temp == 77) 
			{
				i++;
				gotoxy(i, j);
				continue;
			}
			if (temp == 75) 
			{
				i--;
				gotoxy(i, j);
				continue;
			}
			if (temp == 80) 
			{
				j++;
				gotoxy(i, j);
				continue;
			}
			if (temp == 72) 
			{
				j--;
				gotoxy(i, j);
				continue;
			}
		}
		else if (temp == 19) 
		{
			printf("save");
			break;
		}
		else if (temp == 18) 
		{
			//open new file
			running = 0;
			break;
		}
		else if (temp == 32) 
		{
			printf(" ");
		}
		else if (temp == '\r') 
		{
			printf("\n");
			if (text[i][j] == NULL)
				text[i][j] = '\0';
			i = 0;
			j++;
		}
		else if (temp == '\b') 
		{
			printf("%c", 8);
		}
		else if (temp == 24)
		{
			break;
		}
		else 
		{
			printf("%c", temp);
			i++;
			text[i][j] = temp;
		}
		
	}
	system("cls");
	for (int k = 0;k<j;k++)
	{
		printf("%s", text[k]);
	}
	//char str[100];
	//gotoxy(0,0);
	//getchar();
	//gets_s(str);
	//printf("*************%s*************", str);
	//temp = getch();
	//printf("%c", temp);




}