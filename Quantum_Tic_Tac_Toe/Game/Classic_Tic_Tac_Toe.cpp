#include<simplecpp>
#include<iostream>
#include<cstdlib>

using namespace std;
char square[10] = {'0','1','2','3','4','5','6','7','8','9'};

int checkWin();
int compCheck(int a);
int levelSelect();
int newGame();
void fillrectangle(int recno,int player,int ai);
bool rectangleCheck(int recno,int c);
void printWhiteRectangle();
int AIselect();

int main()
{
    for(int q=0;;)
        {
        if(q==1)
            {closeCanvas();}

        int difficulty,AI;
        AI=AIselect();
        closeCanvas();
        if(AI==1)
            {
            difficulty=levelSelect();
            closeCanvas();
            }
        initCanvas("Classic Tic Tac Toe",700,700);

        for(int p=0;p<10;p++)
            {square[p]=p+48;}
        int over[10];



        for(int f=0;f<10;f++)
            {over[f]=0;}

        Rectangle big(350,350,600,600);
        Rectangle R1(350,350,200,600);
        Rectangle R2(350,350,600,200);
        big.imprint();
        R1.imprint();
        R2.imprint();

        Text gamename(350,25,"CLASSIC TIC TAC TOE");
        gamename.imprint();
        gamename.setColor(COLOR(0,180,20));

        Rectangle r3(550,25,150,30);
        r3.imprint();

        Text newgame(550,25,"New Game");
        newgame.setColor(COLOR("purple"));
        newgame.imprint();


        for(int i=0;;)
            {
            int a,selectedrecno,ax,ay;
            if(i%2==0)
                {
                printWhiteRectangle();
                Text playername(350,675,"PLAYER 1'S TURN");
                playername.imprint();
                a=getClick();
                ax=a/65536;
                ay=a%65536;
                if((ax<625)&&(ax>475)&&(ay>10)&&(ay<40))
                    {
                    q=1;
                    closeCanvas();
                    system("./Quantum_Tic_Tac_Toe");
                    }

                }
            if(i%2==1)
                {
                printWhiteRectangle();
                if(AI==0)
                    {
                    Text playername(350,675,"PLAYER 2'S TURN");
                    playername.imprint();
                    a=getClick();
                    ax=a/65536;
                    ay=a%65536;
                   if((ax<625)&&(ax>475)&&(ay>10)&&(ay<40))
                    {
                    q=1;
                    closeCanvas();
                    system("./Quantum_Tic_Tac_Toe");
                    }
                    }
                if(AI==1)
                    {
                    Text playername(350,675,"  COMP'S TURN");
                    wait(0.1);
                if(compCheck(difficulty)!=0)
                    {
                    int k,j;

                    if(compCheck(difficulty)<4)k=0;
                    if(compCheck(difficulty)>3&&compCheck(difficulty)<7)k=1;
                    if(compCheck(difficulty)>6)k=2;
                    if(compCheck(difficulty)%3==1)j=0;
                    if(compCheck(difficulty)%3==2)j=1;
                    if(compCheck(difficulty)%3==0)j=2;
                    a=(50+100*(2*j+1))*65536+(50+100*(2*k+1));
                    }
                else
                    {a=(((rand()%600)+50)*65536)+(((rand()%600)+50));}
                    }
                }

            selectedrecno=0;
            for(int d=1;d<10;d++)
                {
                if(rectangleCheck(d,a)&&over[d]==0)
                    {selectedrecno=d;}
                }
            if(selectedrecno==0)
                {continue;}

            if(i%2==0)square[selectedrecno]='x';
            if(i%2==1)square[selectedrecno]='o';

            fillrectangle(selectedrecno,i%2,AI);

            if(checkWin()==1)
                {
                q=1;
                newGame();
                closeCanvas();
                system("./Quantum_Tic_Tac_Toe");
                }
            if(checkWin()==0)
                {
                printWhiteRectangle();
                Text draw(350,675,"game DRAW :( ");
                draw.imprint();
                q=1;
                newGame();
                closeCanvas();
                system("./Quantum_Tic_Tac_Toe");
                }
            i++;
            over[selectedrecno]=1;
        }



    }
}








int checkWin()
{

	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                    && square[4] != '4' && square[5] != '5' && square[6] != '6'
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}




int compCheck(int a)
{
    if(a==1)
        {
        int sum=0;
        for(int j=1;j<10;j++)
            {
            if(j!=5)
                {
                if((square[j]=='x')||(square[j]=='o'))
                    {sum++;}
                }
            }
    if(sum==0)return 3;
    if(sum==1)return 5;
        }



    for(int i=1;i<10;i++)
        {
        if((square[i]!='x')&&(square[i]!='o'))
            {
            square[i]='o';


            if(checkWin()==1)
                {
                square[i]=i+48;
                return i;
                }
            square[i]=i+48;

            }
        }

    for(int i=1;i<10;i++)
        {
        if((square[i]!='x')&&(square[i]!='o'))
            {
            square[i]='x';

            if(checkWin()==1)
                {
                square[i]=i+48;
                return i;
                }
            square[i]=i+48;


            }
        }


return 0;

}





bool rectangleCheck(int recno,int c)
{
    int j,k,x,y;
    if(recno<4)k=0;
    if(recno>3&&recno<7)k=1;
    if(recno>6)k=2;
    if(recno%3==1)j=0;
    if(recno%3==2)j=1;
    if(recno%3==0)j=2;
    x=c/65536;
    y=c%65536;
    if((x>=(50+j*200))&&x<=((50+(j+1)*200))&&(y>=(50+k*200))&&(y<=(50+(k+1)*200)))return 1;

    else return 0;
}


void fillrectangle(int recno,int player,int ai)
{
    int j,k;
    if(recno<4)k=0;
    if(recno>3&&recno<7)k=1;
    if(recno>6)k=2;
    if(recno%3==1)j=0;
    if(recno%3==2)j=1;
    if(recno%3==0)j=2;
    if(player==0)
        {
        Rectangle recname(50+100*(2*j+1),50+100*(2*k+1),180,180);
        recname.setColor(COLOR(0,205,0));
        recname.setFill();
        recname.imprint();
        if(checkWin()==1)
            {
            printWhiteRectangle();
            Text playerwin1(350,675,"PLAYER 1 WINS........GAME OVER");
            playerwin1.imprint();
            }
        }
    if(player==1)
        {
        Circle circname(50+100*(2*j+1),50+100*(2*k+1),90);
        circname.setColor(COLOR(0,150,200));
        circname.setFill();
        circname.imprint();
        if(checkWin()==1)
            {
            if(ai==1)
            {
            printWhiteRectangle();
            Text playerwin2(350,675,"COMPUTER WINS........GAME OVER");
            playerwin2.imprint();}
            else
            {
            printWhiteRectangle();
            Text playerwin2(350,675,"PLAYER 2 WINS........GAME OVER");
            playerwin2.imprint();
            }
            }
        }
return ;
}


int levelSelect()
{
    initCanvas("Tic Tac Toe",700,700);

    Rectangle r(350,200,182,32);
    r.imprint();
    Rectangle gamename(350,200,180,30);
    gamename.setColor(COLOR(0,205,0));
    gamename.setFill();
    gamename.imprint();

    Text gameName(350,200,"CLASSIC TIC TAC TOE");
    gameName.setColor(COLOR("blue"));
    gameName.imprint();

    Text level(250,300,"Choose Difficulty:");
    level.imprint();

    Rectangle rr(400,400,100,30);
    rr.imprint();

    Text easy(400,400,"Easy");
    easy.setColor(COLOR("blue"));
    easy.imprint();

    Rectangle r2(400,500,100,30);
    r2.imprint();

    Text hard(400,500,"Hard");
    hard.setColor(COLOR("red"));
    hard.imprint();

    int a,x,y;
    for(;;)
        {
        a=getClick();
        x=a/65536;
        y=a%65536;

        if((x<450)&&(x>350)&&(y>370)&&(y<430))
            {return 0;}
        if((x<450)&&(x>350)&&(y>470)&&(y<530))
            {return 1;}
        }


}


int newGame()
{
    int a,x,y;
    for(;;)
        {
        a=getClick();
        x=a/65536;
        y=a%65536;
        if((x<625)&&(x>475)&&(y>10)&&(y<40)){return 1;}
        else continue;
        }

}


void printWhiteRectangle()
{
    Rectangle r(350,675,700,25);
    r.setColor(COLOR("white"));
    r.setFill();
    r.imprint();
    return;
}



int AIselect()
{
    initCanvas("Classic Tic Tac Toe",700,700);

    Rectangle r(350,200,182,32);
    r.imprint();
    Rectangle gamename(350,200,180,30);
    gamename.setColor(COLOR(0,205,0));
    gamename.setFill();
    gamename.imprint();

    Text gameName(350,200,"CLASSIC TIC TAC TOE");
    gameName.setColor(COLOR("blue"));
    gameName.imprint();
    Rectangle rrr(350,400,100,30);
    rrr.imprint();

    Text one(350,400,"SINGLE PLAYER");
    one.setColor(COLOR("blue"));
    one.imprint();

    Rectangle r2(350,500,100,30);
    r2.imprint();

    Text two(350,500,"TWO PLAYER");
    two.setColor(COLOR("red"));
    two.imprint();

    int a,x,y;
    for(;;)
        {
        a=getClick();
        x=a/65536;
        y=a%65536;

        if((x<425)&&(x>275)&&(y>385)&&(y<415))
            {return 1;}
        if((x<425)&&(x>275)&&(y>465)&&(y<515))
            {return 0;}
        }


}
