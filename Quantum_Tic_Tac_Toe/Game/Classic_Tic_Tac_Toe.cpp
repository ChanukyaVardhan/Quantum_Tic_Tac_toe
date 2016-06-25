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
        {
            closeCanvas();
        }

        int difficulty,AI;
        AI=AIselect();// This function will be the first screen creator where we will be seeing the single and double player selection
        closeCanvas();
        if(AI==1)// AI = 1 implies Single player
        {
            //levelselect(), this function will be the one containing the easy and hard options screen.
            difficulty=levelSelect();// difficulty = 0 implies easy and if = 1 implies hard
            closeCanvas();
        }
        initCanvas("Classic Tic Tac Toe",700,700);

        for(int p=0;p<10;p++)// This is used to store the present stage of the game in terms of 'x' and 'o'.
            {square[p]=p+48;}

        int over[10];// This is used to check if the present rectangle is selected or not. 0 implies not selected.
        for(int f=0;f<10;f++)
            {over[f]=0;}

        // (xcenter, ycenter, width, depth)
        Rectangle big(350,350,600,600);// Outer rectangle
        Rectangle R1(350,350,200,600);// Inner rectangle
        Rectangle R2(350,350,600,200);// Inner rectangle
        big.imprint();
        R1.imprint();
        R2.imprint();

        Text gamename(350,25,"CLASSIC TIC TAC TOE");
        gamename.imprint();
        gamename.setColor(COLOR(0,180,20));

        Rectangle r3(550,25,150,30);
        r3.imprint();

        Text newgame(550,25,"New Game");// This is used to create a new game and if clicked it goes back to the quantum tic tac toe stage.
        newgame.setColor(COLOR("purple"));
        newgame.imprint();

        for(int i=0;;)
        {
            int a,selectedrecno,ax,ay;
            if(i%2==0)// Implies player 1's turn
            {
                printWhiteRectangle();// This is like a patch below where the information is being printed.
                Text playername(350,675,"PLAYER 1'S TURN");
                playername.imprint();
                a=getClick();
                ax=a/65536;
                ay=a%65536;
                if((ax<625)&&(ax>475)&&(ay>10)&&(ay<40))// The player selected the new game.
                {
                    q=1;
                    closeCanvas();
                    system("./Quantum_Tic_Tac_Toe");
                }
            }
            if(i%2==1)// Implies player 2 or computer's turn.
            {
                printWhiteRectangle();
                if(AI==0)// Implies that it is two player game
                {
                    Text playername(350,675,"PLAYER 2'S TURN");
                    playername.imprint();
                    a=getClick();
                    ax=a/65536;
                    ay=a%65536;
                    if((ax<625)&&(ax>475)&&(ay>10)&&(ay<40))// The player selected the new game.
                    {
                        q=1;
                        closeCanvas();
                        system("./Quantum_Tic_Tac_Toe");
                    }
                }
                if(AI==1)// Implies computer's turn.
                {
                    Text playername(350,675,"  COMP'S TURN");
                    wait(0.1);
                    if(compCheck(difficulty)!=0)// If the level of difficulty is hard and position is decided by the rectangle then the position of the computer turn will be based on the present arrangement.
                    {
                        int k,j;// Setting the value of j,k so that the circle's position can be set exactly.

                        if(compCheck(difficulty)<4)k=0;
                        if(compCheck(difficulty)>3&&compCheck(difficulty)<7)k=1;
                        if(compCheck(difficulty)>6)k=2;
                        if(compCheck(difficulty)%3==1)j=0;
                        if(compCheck(difficulty)%3==2)j=1;
                        if(compCheck(difficulty)%3==0)j=2;
                        a=(50+100*(2*j+1))*65536+(50+100*(2*k+1));
                    }
                    else// implies that the level is easy or level is hard with no rectangle position to decide by the computer, then the position is selected using the rand() i.e., randomly.
                    {
                        a=(((rand()%600)+50)*65536)+(((rand()%600)+50));
                    }
                }
            }

            selectedrecno=0;// Getting the selected rectangle
            for(int d=1;d<10;d++)
            {
                if(rectangleCheck(d,a)&&over[d]==0)
                {
                    selectedrecno=d;
                }
            }
            if(selectedrecno==0)
            {
                continue;
            }

            if(i%2==0)// implies player 1 selected, then it means a cross(rectangle) needs to be put.
            {
                square[selectedrecno]='x';
            }
            if(i%2==1)// implies player 2 or computer selected, then it means a circle needs to be put.
            {
                square[selectedrecno]='o';
            }

            fillrectangle(selectedrecno,i%2,AI);

            if(checkWin()==1)// Some player won the game.
            {
                q=1;
                newGame();
                closeCanvas();
                system("./Quantum_Tic_Tac_Toe");
            }
            if(checkWin()==0)// Game is a draw.
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
            over[selectedrecno]=1;// Making that selectedrectangle to be filled.
        }
    }
}

int checkWin()// This function will check if the game is finished with the square array.
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
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}

int compCheck(int a)// This returns the rectangle number where the computer should place the circle.
{
    if(a==1)
    {
        int sum=0;
        for(int j=1;j<10;j++)
        {
            if(j!=5)
            {
                if((square[j]=='x')||(square[j]=='o'))
                {
                    sum++;
                }
            }
        }
        if(sum==0)return 3;// sum = 0 implies that player 1 placed x at the center, then returning top right rectangle.
        if(sum==1)return 5;// sum = 1 implies that player 1 placed x not at the center, then returning center rectangle.
    }

    for(int i=1;i<10;i++)// First checking the position that will make the computer win.
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
    // If there is no position that makes the computer win, then check for the position that will make the player 1 win the game.
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

    return 0;// 0 is returned if we can't decide anything.
}

bool rectangleCheck(int recno,int c)//Checking if the mouse clicked rectangle is recno or not
{
    int j,k,x,y;// 'j' is useful for the x co-ordinate's of the rectangle and 'k' is useful for the y co-ordinate's of the rectangle.
    if(recno<4)k=0;
    if(recno>3&&recno<7)k=1;
    if(recno>6)k=2;
    if(recno%3==1)j=0;
    if(recno%3==2)j=1;
    if(recno%3==0)j=2;
    x=c/65536;
    y=c%65536;

    if((x>=(50+j*200))&&x<=((50+(j+1)*200))&&(y>=(50+k*200))&&(y<=(50+(k+1)*200)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
    if(player==0)// Printing a rectangle
    {
        Rectangle recname(50+100*(2*j+1),50+100*(2*k+1),180,180);
        recname.setColor(COLOR(0,205,0));
        recname.setFill();
        recname.imprint();
        if(checkWin()==1)// Checking if the game is over by this move.
        {
            printWhiteRectangle();
            Text playerwin1(350,675,"PLAYER 1 WINS........GAME OVER");
            playerwin1.imprint();
        }
    }
    if(player==1)// Printing teh circle
    {
        Circle circname(50+100*(2*j+1),50+100*(2*k+1),90);
        circname.setColor(COLOR(0,150,200));
        circname.setFill();
        circname.imprint();
        if(checkWin()==1)// Checking if the game is over by this move.
        {
            if(ai==1)
            {
                printWhiteRectangle();
                Text playerwin2(350,675,"COMPUTER WINS........GAME OVER");
                playerwin2.imprint();
            }
            else
            {
                printWhiteRectangle();
                Text playerwin2(350,675,"PLAYER 2 WINS........GAME OVER");
                playerwin2.imprint();
            }
        }
    }
    return;
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
        {
            return 0;
        }
        if((x<450)&&(x>350)&&(y>470)&&(y<530))
        {
            return 1;
        }
    }
}

int newGame()// This function waits for a click and waits till the newgame is selected.
{
    int a,x,y;
    for(;;)
    {
        a=getClick();
        x=a/65536;
        y=a%65536;

        if((x<625)&&(x>475)&&(y>10)&&(y<40))
        {
            return 1;
        }
        else
        {
            continue;
        }
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
        {
            return 1;
        }
        if((x<425)&&(x>275)&&(y>465)&&(y<515))
        {
            return 0;
        }
    }
}
