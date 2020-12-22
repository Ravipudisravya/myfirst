#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include <windows.h>
///This will set the forground color for printing in a console window.
void SetColor(int ForgC)
{
     WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     ///Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     ///This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
     ///A return value... indicating how many chars were written
     ///   not used but we need to capture this since it will be
     ///   written anyway (passing NULL causes an access violation).
     DWORD count;
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          ///This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          ///This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

COORD coord = {0,0}; ///set the cordinate to 0, 0 (top-left corner of window);
void gotoxy(int x, int y){
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearWindow(){
    int i,j;
    for(i = 37; i < 78; i++){
        for(j = 7; j < 25; j++){
            gotoxy(i,j);printf(" ");
        }
    }
    return;
}

void window(){
    SetColor(35);
printf("\n\t\t\t**");printf("\n\t\t\tCRICKET PREMIERE LEAGUE\n ");printf("\n\t\t\t*");
printf("\n\t\t\tVASAVI COLLEGE OF ENGINEERING\n");
    printf("\n\t\t\t**\n");

    SetColor(17);

}
int sum1=0;
int sum2=0;
int w2=0;
int w1=0;
int b2=1;
int b1=1;
int main()

{

main:

    system("cls");    /* **Main menu ***  */

    ClearConsoleToColors(17,15);
    SetConsoleTitle("\n\tCRICKET SCORE READER");
	window();

    printf("\n\n\n\t\tMAIN MENU\n\t\t=====================\n\t\t[1] INSTRUCTIONS\n\t\t[2] CHECK WHEATHER\n\t\t[3] SELECTION OF TEAMS\n\t\t[4] PREVIOUS MATCH DETAILS\n\t\t[5] GRAPH REPRESENTATION\n\t\t[0] EXIT\n\t\t=================\n\t\t");
	int ch;

    printf("ENTER THE CHOICE:");

    scanf("%d",&ch);

    switch(ch)

    {

    case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

        break;
        /* ***Instructions**  */

    case 1:
	system("cls");
    printf("\n\t\t================================================================================================\n\t\t\t\t\tINSTRUCTIONS TO BE FOLLOWED IN THE MATCH\n\t\t================================================================================================\n\n");
    printf("0:Dot Ball\n1:Single Run\n2:Two Runs\n3:Three Runs\n4:Four\n5:No Ball/Wide/LB/B+4\n6:Six\n7;No Ball+6\n8:Wicket\n");
	break;

        /* ***check whether***  */

    case 2:

        system("cls");

        printf("\n\t\t================================================================================================\n\t\t\t\t\tCHECK WHEATHER\n\t\t================================================================================================\n\n");

	float Temp;
   printf("ENTER THE TEMPERATURE:\n");
	scanf("%f",&Temp);
	if(Temp<10)
	{
	printf("CANNOT PLAY\n");
	exit(0);
	}
	else
	{
	printf("GOOD LUCK FOR THE MATCH\n");
	}

        break;

        /* ***selection of teams**  */

    case 3:

        system("cls");


            printf("\n\n\t ..::SELECTION OF TEAMS..:: \n\t===========================\n\t");
		char t1[10];
    char t2[10];
 char filename[15];
printf("\n ENTER THE TEAMS PARTICIPATING:\n");
    printf("ENTER THE FIRST TEAM\n");
    scanf("%s",t1);
    printf("ENTER THE SECOND TEAM\n");
    scanf("%s",t2);



        /* ***MAIN MATCH****/

	FILE *fp;
	 printf("Enter the filename to be opened with date(match 12-07-20)\n");
    		scanf("%s",filename);
        fp = fopen(filename,"ab+");
    //int b1=1;
    //int b2=1;
    //int sum1=0;
    //int sum2=0;
    //int w1=0;
    //int w2=0;
    int r1;
    int r2;
	 SetColor(17);
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);
	}else{
    printf("%s innings:\n",t1);
	 fprintf(fp,"%s innings:\n",t1);
    while(b1<=120)
    {

        printf("status of ball %d:",b1);
	fprintf(fp,"status of ball %d:",b1);
        scanf("%d",&r1);
	fprintf(fp,"%d\n",r1);
        if(r1==8)
        {
            w1++;
            if(w1<=9)
            {
                printf("%s loses a wicket,%d wickets remaining\n",t1,(10-w1));	fprintf(fp,"%s won the match over %s by %d wickets in %d balls\n",t2,t1,w2,b2);
            }
            if(w1==10)
            {
                printf("%s innings came to an end\n",t1);
                break;
            }
        }
        else if(r1>8)
        {
            printf("invalid no.\n please read the instructions carefully \n");
            continue;
        }
        else if(r1==7)
        {
            printf("free hit so no wicket will be considered even if wicket falls\n");
            b1--;
            sum1=sum1+r1;
        }
        else
        {
            sum1=sum1+r1;
        }
        b1++;
    }



}
    printf("%s requires %d runs to win in 120 balls at a run rate of %d\n",t2,sum1+1,(sum1+1)/20);

	fprintf(fp,"%s requires %d runs to win in 120 balls at a run rate of %d\n",t2,sum1+1,(sum1+1)/20);
    printf("%s innings:\n",t2);
	fprintf(fp,"%s innings:\n",t2);
    while(b2<=120 && sum2<=sum1)
    {
        printf("status of ball %d:",b2);
	 fprintf(fp,"status of ball %d:",b2);
        scanf("%d",&r2);
	fprintf(fp,"%d\n",r1);
        if(r2==8)
        {
            w2++;
            if(w2<=9)
            {
                printf("%s loses a wicket,%d wickets remaining\n",t2,(10-w2));
            }
            if(w2==10)
            {
                printf("%s innings came to an end\n",t2);
                break;

            }
        }
        else if(r2>8)
        {
            printf("invalid no.\n please read the instructions carefully\n");
            continue;
        }
        else if(r2==7)
        {
            printf("free hit so no wicket will be considered even if wicket falls\n");
            b2--;
            sum2=sum2+r2;
        }
        else
        {
            sum2=sum2+r2;
        }
        b2++;
    }


    printf("%s total is %d\n",t1,sum1);
	fprintf(fp,"%s total is %d\n",t1,sum1);
    printf("%s total is %d\n",t2,sum2);
     fprintf(fp,"%s total is %d\n",t2,sum2);
    if(sum1>sum2)
    {
        printf("%s won the match over %s by %d wickets in %d balls\n",t1,t2,w1,b1);
	 fprintf(fp,"%s won the match over %s by %d wickets in %d balls\n",t1,t2,w1,b1);
    }
    if(sum2>sum1)
    {
        printf("%s won the match over %s by %d wickets in %d balls\n",t2,t1,w2,b2);
	fprintf(fp,"%s won the match over %s by %d wickets in %d balls\n",t2,t1,w2,b2);
    }
SetColor(17);
fclose(fp);	fprintf(fp,"%s won the match over %s by %d wickets in %d balls\n",t2,t1,w2,b2);	fprintf(fp,"%s won the match over %s by %d wickets in %d balls\n",t2,t1,w2,b2);

     a: if(sum2==sum1)
    {
        FILE *fp;
	char filename[15];
	 printf("Enter the filename to be opened with date(match 12-07-20)\n");
    scanf("%s", filename);
        fp = fopen(filename,"ab+");
        //int b1=1;
        //int b2=1;
       // int sum1=0;
        //int sum2=0;
        //int w1=0;
        //int w2=0;
        int r1;
        int r2;
        SetColor(17);
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);
	}else
	{
    printf("%s innings:\n",t1);
	 fprintf(fp,"%s innings:\n",t1);
        printf("Let's Begin Super Over\n");
        printf("%s innings\n",t1);
        while(b1<=6)
        {
            printf("status of ball %d:",b1);
            fprintf(fp,"status of ball %d:",b1);
            scanf("%d",&r1);
            fprintf(fp,"%d\n",r1);
            if(r1==8)
            {
                w1++;
                if(w1==1)
                {
                    printf("%s loses a wicket,one wicket remaining\n",t1);

                }
                if(w1==2)
                {
                    printf("%s innings has came to an end\n",t1);
                    printf("%s requires %d runs to win in 6 balls at a run rate of %d\n",t2,sum1+1,sum1+1);
                    break;
                }
            }
                else if(r1>8)
                {
                    printf("invalid no.\n please read the instructions carefully\n");
                    continue;
                }
                else if(r1==7)
                {
                    printf("free hit\n");
                    b1--;
                    sum1=sum1+r1;
                }
                else
                {
                    sum1=sum1+r1;
                }
                b1++;
            }
	}
            b1=b1-1;
            fprintf(fp,"%s requires %d runs to win in 6 balls at a run rate of %d\n",t2,sum1+1,(sum1+1)/20);
            printf("%s innings\n",t2);
            fprintf(fp,"%s innings:\n",t2);
          while(b2<=6 && sum2<=sum1)
      {
        printf("status of ball %d:",b2);
        fprintf(fp,"status of ball %d:",b2);
        scanf("%d",&r2);
        fprintf(fp,"%d\n",r2);
        if(r2==8)
        {   w2++;
            if(w2==1)
            {
                printf("%s loses a wicket, one wicket remaining\n",t2);

            }
            if(w2==2)
            {
                printf("%s innings has come to an end\n",t2);
                break;
            }
        }
        else if(r2>8)
        {
            printf("invalid no.\nplease carefully read the instructions\n");
            continue;
        }
        else if(r2==7)
        {
            printf("free hit so no wicket will be considered even if wicket falls.Hence do not enter 8\n");
            b2--;
            sum2=sum2+r2;
        }
        else
        {
            sum2=sum2+r2;
        }
        b2++;
       }
       b2=b2-1;
       printf("A total: %d\n",sum1);
       fprintf(fp,"%s total is %d\n",t1,sum1);
       printf("B total:%d\n",sum2);
       fprintf(fp,"%s total is %d\n",t2,sum2);
       if(sum1>sum2)
       {
           printf("%s won over %s by %d wickets in %d balls\n",t1,t2,w1,b1);
           fprintf(fp,"%s won the match over %s by %d wickets in %d balls\n",t1,t2,w1,b1);
       }
       if(sum1<sum2)
       {
           printf("%s won over %s by %d wickets in %d balls\n",t2,t1,w2,b2);
           	fprintf(fp,"%s won the match over %s by %d wickets in %d balls\n",t2,t1,w2,b2);
       }
       if(sum1==sum2)
       {
           goto a;
       }
       fclose(fp);
       break;
      }

   case 4:


	   system("cls");

	   printf("\n\t\t================================================================================================\n\t\t\t\t\tPREVIOUS MATCH DETAILS\n\t\t================================================================================================\n\n");

		FILE *fptr;

     char filename1[100];
     char c;

     printf("Enter the filename to open \n");
     scanf("%s", filename1);

    // Open file
     fptr= fopen(filename1, "r");
     if (fptr == NULL)
    {
       printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

     fclose(fptr);
     break;
    /* ***BAR GRAPH OF TWO TEAMS*** */

	case 5:

	    system("cls");

	 printf("\n\t\t================================================================================================\n\t\t\t\t\tBAR GRAPH\n\t\t================================================================================================\n\n");
    // gm is Graphics mode which is
    // a computer display mode that
    // generates image using pixels.
    // DETECT is a macro defined in
    // "graphics.h" header file

    int gd = DETECT, gm;

    // initgraph initializes the
    // graphics system by loading a
    // graphics driver from disk
    initgraph(&gd, &gm, "");
    settextstyle(10,1,3);

    // location of sides
    int left, top, right, bottom;

    // left, top, right, bottom denotes
    // location of rectangular bar
    bar(left = 150, top = 350-sum1,
    right = 190, bottom = 350);
   outtextxy(192,370,t1);

    bar(left = 260, top = 350-sum2,
    right = 300, bottom = 350);
    outtextxy(302,370,t2);

    //bar(left = 290, top = 200,
    //right = 330, bottom = 350);

    // y axis line
    SetColor(45);
    outtextxy(90,70,"SCORES");
    line(100, 20, 100, 350);
    settextstyle(10,0,3);
    // x axis line
    line(100, 350, 500, 350);
    outtextxy(490,390,"INNINGS");

    getch();

    // closegraph function closes the
    // graphics mode and deallocates
    // all memory allocated by
    // graphics system .
    closegraph();
	    break;
   /*default:

        printf("INVALID CHOICE");

        break;*/

    }

    printf("\n\n\n..::ENTER THE CHOICE:\n\n\t[1] MAIN MENU\t\t[0] EXIT\n");

    scanf("%d",&ch);

    switch (ch)
	{

    case 1:

        goto main;

    case 0:

        break;

    default:

        printf("INVALID CHOICE");

        break;

    }

    return 0;

}