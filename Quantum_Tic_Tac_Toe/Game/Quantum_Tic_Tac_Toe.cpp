#include<simplecpp>
#include<iostream>
#include<cstdlib>

using namespace std;

struct step
{
int value,block1,block2;
};int A[10];

void initialInterface();
void formRectangle(int a1,int a2,int x,int y);
int xCoordinate(int a);
int yCoordinate(int a);
int inputRecno(int c);
bool rectangleCheck(int recno,int c);
bool checkInputValidity(int **quantumTicTacToe,int index1,int index2,int chance);
void displayInput(int **quantumTicTacToe,int clickval1,int i);
void printBackground();
void smallCircle(int a, int b,int c);
bool checkCircuit(int ** quantumTicTacToe,int input1,int input2,int previnput1,step s[],int A[],int &n);
void collapse(int **quantumTicTacToe,int chosenvalue,step s[],int collapsevalue);
int checkWin(int **quantumTicTacToe,int &pointsofplayer1,int &pointsofplayer2);
int newGame();


int main()
{
    initCanvas("Tic Tac Toe",700,700);//Initialisation of screen which asks the user to choose the game

    Rectangle r(350,200,182,32);
    r.imprint();
    Rectangle gamename(350,200,180,30);
    gamename.setColor(COLOR(0,205,0));
    gamename.setFill();
    gamename.imprint();

    Text gameName(350,200,"TIC TAC TOE");
    gameName.setColor(COLOR("blue"));
    gameName.imprint();


    Rectangle r1(350,400,152,32);
    r1.imprint();

    Rectangle classic(350,400,150,30);
    classic.setColor(COLOR(255,255,200));
    classic.setFill();
    classic.imprint();

    Text Classic(350,400,"CLASSIC");
    Classic.setColor(COLOR("blue"));
    Classic.imprint();


    Rectangle r2(350,500,152,32);
    r2.imprint();

    Rectangle quantum(350,500,150,30);
    quantum.setColor(COLOR(255,255,200));
    quantum.setFill();
    quantum.imprint();

    Text Quantum(350,500,"QUANTUM");
    Quantum.setColor(COLOR("red"));
    Quantum.imprint();


int a,x,y,pointsofplayer1,pointsofplayer2;
for(;;)
{
    a=getClick();
    x=a/65536;
    y=a%65536;

    if((x<425)&&(x>275)&&(y>370)&&(y<430))
    {
    closeCanvas();system("./Classic_Tic_Tac_Toe");//opens classic tic tac toe file
    }


    if((x<425)&&(x>275)&&(y>485)&&(y<515))
    {
    closeCanvas();
    bool newgame=1;

    for(int q=0;newgame==1;q++)//one loop represents a game of quantum tic tacc toe
    {
    if((q>0)&&(newgame==1))
        {
        system("./Quantum_Tic_Tac_Toe");closeCanvas();//opens the file of quantum tic tac toe
        }

    newgame=0;
    step s[37];


    for(int i=0;i<37;i++)//initialissation of members of structures
        {
        s[i].value=0;
        s[i].block1=0;
        s[i].block2=0;
        }


    initialInterface();
    int **quantumTicTacToe,chosenvalue;
    quantumTicTacToe=new int*[10];//declartion of main game array
    for(int i=0;i<10;i++)
        {
        quantumTicTacToe[i]=new int[10];

        if (quantumTicTacToe[i]==NULL)
            {return -2;}
        }

    if (quantumTicTacToe!=NULL)
        {
        for(int i=0;i<10;i++)//assigning zero to all elements of array
            {
                for(int j=0;j<10;j++)
                    {
                    quantumTicTacToe[i][j]=0;
                    }

            }

        }
    else
        {return -1;}

    for(int i=0;;i++)
        {

        int clickval1,clickval2,inputRec1,inputRec2;
        bool validity;
        if(i%2==0)
            {
            printBackground();
            Text playername(770,250,"To move : ");//asks player1 to move
            playername.imprint();

            Rectangle turn1(850,250,30,30);
            turn1.setColor(COLOR(0,205,0));
            turn1.setFill();
            turn1.imprint();

            Text turnname(850,250,"1");
            turnname.imprint();
            }
       if(i%2==1)
            {
            printBackground();
            Text playername(770,250,"To move : ");//asks player2 to move
            playername.imprint();

             Circle turn2(850,250,15);
            turn2.setColor(COLOR(0,150,200));
            turn2.setFill();
            turn2.imprint();
            Text turnname(850,250,"2");
            turnname.imprint();
            }

       do{
        clickval1=getClick();
        validity=1;//status of validity denotes that the input is valid(if validity=1)
        if((clickval1/65536>725)&&(clickval1/65536<875)&&(clickval1%65536>55)&&(clickval1%65536<85))
        {newgame=1;break;}//newgame check


        if(clickval1/65536<50||clickval1/65536>650||clickval1%65536<50||clickval1%65536>650)
            {//check for input within big box
            validity=0;
            Text invalid(800,300,"INVALID SELECTION");
            invalid.setColor(COLOR(210,0,0));
            wait(0.5);
            continue;
            }

        inputRec1=inputRecno(clickval1);//inputRec1 denotes the rectangle number of 1st input by the player

        if((inputRec1==checkWin(quantumTicTacToe,pointsofplayer1,pointsofplayer2))&&(i%2==0))
            {
            Text invalid(800,300,"INVALID SELECTION")  ;//since there is no possible next move
            invalid.setColor(COLOR(210,0,0));
            wait(0.5);
            validity=0;
            continue;
            }

        if(quantumTicTacToe[inputRec1][0]!=0)
            {
            Text invalid(800,300,"INVALID SELECTION");//block is already collapsed.
            invalid.setColor(COLOR(210,0,0));
            wait(0.5);
            validity=0;
            continue;
            }
         }while(validity==0);

        if(newgame==1)
        {break;}

        displayInput(quantumTicTacToe,clickval1,i);//displays the first selection of player

        do{
         validity=1;
         clickval2=getClick();
         if((clickval2/65536>725)&&(clickval2/65536<875)&&(clickval2%65536>55)&&(clickval2%65536<85))
         {newgame=1;break;}//newgame check

         if((clickval2/65536<50)||(clickval2/65536>650)||(clickval2%65536<50)||(clickval2%65536>650))
            {
            validity=0;//selection is done out of big rectangle.
            Text invalid(800,300,"INVALID SELECTION");
            invalid.setColor(COLOR(210,0,0));
            wait(0.5);
            continue;
            }
        inputRec2=inputRecno(clickval2);//inputRec2 denotes the rectangle numberof 2nd input by the player

        if(quantumTicTacToe[inputRec2][0]!=0)//collapse check
            {
            Text invalid(800,300,"INVALID SELECTION");
            invalid.setColor(COLOR(210,0,0));
            wait(0.5);
            validity=0;
            continue;
            }

        if(checkInputValidity(quantumTicTacToe,inputRec1,inputRec2,i)==0)//main validity check
            {
            Text invalid(800,300,"INVALID SELECTION");
            invalid.setColor(COLOR(210,0,0));
            wait(0.5);
            validity=0;
            continue;
            }
        }while(validity==0);


       if(newgame==1)
       {newgame=1;break;}

       displayInput(quantumTicTacToe,clickval2,i);

int n=1;
       if (checkCircuit(quantumTicTacToe,inputRec1,inputRec2,0,s,A,n)){
            for(int y=1;y<10;y++){
            if(A[y]==0)
            A[y]=A[y-1];}
            Text collapses(800,200,"COLLAPSE:");
            collapses.setColor(COLOR("red"));
            Line loop1((xCoordinate(inputRec1)*200)-50,(yCoordinate(inputRec1)*200)-50,(xCoordinate(inputRec2)*200)-50,(yCoordinate(inputRec2)*200)-50);
            loop1.setColor(COLOR(200,150,200));//circuit is formed by joining lines.
            loop1.show();

            Line loop2((xCoordinate(A[1])*200)-50,(yCoordinate(A[1])*200)-50,(xCoordinate(A[2])*200)-50,(yCoordinate(A[2])*200)-50);
            loop2.setColor(COLOR(200,150,200));
            loop2.show();


            Line loop3((xCoordinate(A[2])*200)-50,(yCoordinate(A[2])*200)-50,(xCoordinate(A[3])*200)-50,(yCoordinate(A[3])*200)-50);
            loop3.setColor(COLOR(200,150,200));
            loop3.show();

            Line loop4((xCoordinate(A[3])*200)-50,(yCoordinate(A[3])*200)-50,(xCoordinate(A[4])*200)-50,(yCoordinate(A[4])*200)-50);
            loop4.setColor(COLOR(200,150,200));
            loop4.show();



            Line loop5((xCoordinate(A[4])*200)-50,(yCoordinate(A[4])*200)-50,(xCoordinate(A[5])*200)-50,(yCoordinate(A[5])*200)-50);
            loop5.setColor(COLOR(200,150,200));
            loop5.show();



            Line loop6((xCoordinate(A[5])*200)-50,(yCoordinate(A[5])*200)-50,(xCoordinate(A[6])*200)-50,(yCoordinate(A[6])*200)-50);
            loop6.setColor(COLOR(200,150,200));
            loop6.show();




            Line loop7((xCoordinate(A[6])*200)-50,(yCoordinate(A[6])*200)-50,(xCoordinate(A[7])*200)-50,(yCoordinate(A[7])*200)-50);
            loop7.setColor(COLOR(200,150,200));
            loop7.show();




            Line loop8((xCoordinate(A[7])*200)-50,(yCoordinate(A[7])*200)-50,(xCoordinate(A[8])*200)-50,(yCoordinate(A[8])*200)-50);
            loop8.setColor(COLOR(200,150,200));
            loop8.show();



            Line loop9((xCoordinate(A[8])*200)-50,(yCoordinate(A[8])*200)-50,(xCoordinate(A[9])*200)-50,(yCoordinate(A[9])*200)-50);
            loop9.setColor(COLOR(200,150,200));
            loop9.show();



        smallCircle((xCoordinate(A[1])*200)-50,(yCoordinate(A[1])*200)-50,150);
        smallCircle((xCoordinate(A[2])*200)-50,(yCoordinate(A[2])*200)-50,150);
        smallCircle((xCoordinate(A[3])*200)-50,(yCoordinate(A[3])*200)-50,150);
        smallCircle((xCoordinate(A[4])*200)-50,(yCoordinate(A[4])*200)-50,150);
        smallCircle((xCoordinate(A[5])*200)-50,(yCoordinate(A[5])*200)-50,150);
        smallCircle((xCoordinate(A[6])*200)-50,(yCoordinate(A[6])*200)-50,150);
        smallCircle((xCoordinate(A[7])*200)-50,(yCoordinate(A[7])*200)-50,150);
        smallCircle((xCoordinate(A[8])*200)-50,(yCoordinate(A[8])*200)-50,150);
        smallCircle((xCoordinate(A[9])*200)-50,(yCoordinate(A[9])*200)-50,150);


            for(int w=1;w<10;w++){A[w]=0;}


            int input;
            do{
                validity=1;
                input =getClick();

                if((input/65536>725)&&(input/65536<875)&&(input%65536>55)&&(input%65536<85))
                {newgame=1;break;}//newgame check

                if((input/65536<50)||(input/65536>650)||(input%65536<50)||(input%65536>650))
                    {//If it's selected outside the game canvas
                    validity=0;
                    Text invalid(800,300,"INVALID SELECTION");
                    invalid.setColor(COLOR(210,0,0));
                    wait(0.5);
                    continue;
                    }

                if((rectangleCheck(inputRec1,input)!=1)&&(rectangleCheck(inputRec2,input)!=1))
                    {//Blocks other than the ones to be selected i.e, the blocks of last move
                    validity=0;
                    Text invalid(800,300,"INVALID SELECTION");
                    invalid.setColor(COLOR(210,0,0));
                    wait(0.5);
                    continue;
                    }

            }while(validity==0);


            if(newgame==1)
            {newgame=1;break;}

            if((input/65536>(50+(xCoordinate(inputRec1)-1)*200)&&(input/65536<(50+(xCoordinate(inputRec1))*200)))&&(input%65536>(50+(yCoordinate(inputRec1)-1)*200)&&(input%65536<(50+(yCoordinate(inputRec1))*200))))
                {loop1.hide();  loop2.hide();  loop3.hide();  loop4.hide();  loop5.hide();
                 loop6.hide();  loop7.hide();  loop8.hide();  loop9.hide();//hides all lines formed above
                chosenvalue=inputRec1;int collapsevalue=i%2+1;
                collapse(quantumTicTacToe,chosenvalue,s,collapsevalue);
                }
            else
               {
               if((input/65536>(50+(xCoordinate(inputRec2)-1)*200)&&(input/65536<(50+(xCoordinate(inputRec2))*200)))&&(input%65536>(50+(yCoordinate(inputRec2)-1)*200)&&(input%65536<(50+(yCoordinate(inputRec2))*200))))
                    {loop1.hide();  loop2.hide();  loop3.hide();  loop4.hide();  loop5.hide();
                  loop6.hide();  loop7.hide();  loop8.hide();  loop9.hide();
                    chosenvalue=inputRec2;int collapsevalue=i%2+1;
                    collapse(quantumTicTacToe,chosenvalue,s,collapsevalue);
                    }
               else
                    {
                    Text invalid(800,300,"INVALID SELECTION");
                    invalid.setColor(COLOR(210,0,0));
                    wait(0.5);
                    }
                }


           }




        s[i].block1=inputRec1;s[i].block2=inputRec2;s[i].value=10*(i%2+1)+i/2+1;//updating values of the structure
         for(int c=1;c<10;c++)
            {
            if(quantumTicTacToe[c][0]%2==1)
                {
                Rectangle big(125+(xCoordinate(c)-1)*200,175+(yCoordinate(c)-1)*200,148,148);
                big.setColor(COLOR(0,205,0));
                big.setFill();
                big.imprint(); //fills the collapsed blocks with the particles present in it
                }

            if(quantumTicTacToe[c][0]%2==0&&quantumTicTacToe[c][0]!=0)
                {
                Circle big(50+(xCoordinate(c)-1)*200+75,175+(yCoordinate(c)-1)*200,74);
                big.setColor(COLOR(0,150,200));
                big.setFill();
                big.imprint();
                }
                }



        if ((checkWin(quantumTicTacToe,pointsofplayer1,pointsofplayer2)==10)||(checkWin(quantumTicTacToe,pointsofplayer1,pointsofplayer2)==11)||(checkWin(quantumTicTacToe,pointsofplayer1,pointsofplayer2)==12))
            {
            Rectangle scoreborder1(810,500,92,22);
            scoreborder1.imprint();

            Rectangle scoreborder2(810,530,92,22);
            scoreborder2.imprint();

            Rectangle player1(810,500,90,20);
            player1.setColor(COLOR(255,255,200));
            player1.setFill();
            player1.imprint();

            Rectangle player2(810,530,90,20);
            player2.setColor(COLOR(255,255,200));
            player2.setFill();
            player2.imprint();

            Text score(800,482,"SCORE");

            Text score1(790,500,"PLAYER");
            score1.setColor(COLOR(0,200,0));

        Rectangle turn1(820,500,15,15);
            turn1.setColor(COLOR(0,205,0));
            turn1.setFill();
            turn1.imprint();

            Text turnname(820,500,"  1 :");
            turnname.imprint();

            Text game1(840,500,pointsofplayer1);
            game1.setColor(COLOR(0,0,200));
            game1.imprint();

            Text score2(790,530,"PLAYER");
            score2.setColor(COLOR(0,0,200));

            Circle turn2(820,530,7.5);
            turn2.setColor(COLOR(0,150,200));
            turn2.setFill();
            turn2.imprint();

            Text turnname2(820,530,"  2 :");
            turnname2.imprint();
            Text game2(840,530,pointsofplayer2);
            game2.setColor(COLOR(0,200,0));
            game2.imprint();

            newgame=newGame();
            break;
            }



        }
        closeCanvas();
        for (int del=0;del<10;del++)
            {
            if (quantumTicTacToe[del]!=NULL)
            {delete []quantumTicTacToe[del];}
            }
        if (quantumTicTacToe!=NULL)
        {delete []quantumTicTacToe;}  //deleting the dynamically allocated arrays
        //end of a game

        }//end of for
        }//end of if
        }//end of for
}



void initialInterface()
{
    initCanvas(" Quantum Tic Tac Toe",950,700);

    Rectangle outer(350,350,600,600);    //border rectangle
    Rectangle column(350,350,200,600);   //middle column rectangle(rectangles inclding 2,5,8)
    Rectangle row(350,350,600,200);      //middle row rectngle(rectangles including 4,5,6)

    outer.imprint();
    row.imprint();
    column.imprint();

    Rectangle headerborder(350,24,152,31);
    headerborder.imprint();

    Rectangle header(350,25,150,30);
    header.setColor(COLOR(0,235,0));
    header.setFill();
    header.imprint();

    Text gamename(350,25,"QUANTUM TIC TAC TOE"); //Title of the game is formed
    gamename.setColor(COLOR(0,0,255));
    gamename.imprint();

    formRectangle(800,70,152,32);

    Rectangle newgamerec(800,70,150,30);
    newgamerec.setColor(COLOR(255,255,200));
    newgamerec.setFill();
    newgamerec.imprint();

    Text newgame(800,70,"New Game");//this
    newgame.setColor(COLOR(200,0,0));
    newgame.imprint();

    Rectangle chatboxborder(800,250,203,43);
    chatboxborder.imprint();

    Rectangle chatbox(800,250,200,40);   //Inorder to intimate players about whose move it is
    chatbox.setColor(COLOR(255,255,200));
    chatbox.setFill();
    chatbox.imprint();


    for(int i=1;i<10;i++)
        {
        formRectangle(125+(i%3)*200,175+(yCoordinate(i)-1)*200,150,150);
        }

    return;
}


void formRectangle(int a1,int a2,int x,int y)
{
    //this function forms a permanent rectangle wlth the given input values
    Rectangle r(a1,a2,x,y); //a1,a2 represents co-ordinates of center of rectangle
    r.imprint();
    return;

}





int xCoordinate(int a)
{
    //"a" denotes the input given by the player
    //returns 1 if a is present in the rectangles 1,4,7.
    //returns 2 if a is present in the rectangles 2,5,8.
    //returns 3 if a is present in the rectangles 3,6,9.
        if(a==1||a==4||a==7){return 1;}
        if(a==2||a==5||a==8){return 2;}
        if(a==3||a==6||a==9){return 3;}
        return -1;
}



int yCoordinate(int a)
{
    //"a" denotes the input given by the player
    //returns 1 if a is present in the rectangles 1,2,3.
    //returns 2 if a is present in the rectangles 4,5,6.
    //returns 3 if a is present in the rectangles 7,8,9.
        if(a>0&&a<4){return 1;}
        if(a>3&&a<7){return 2;}
        if(a>6&&a<10){return 3;}
        return -1;
}



int inputRecno(int c)
{
    //this takes the input given by the player and returns the rectangle number of the appropriate input
    for(int i=1;i<10;i++)
        {
            if(rectangleCheck(i,c))
               {return i;}
        }
    return -1;
}


bool rectangleCheck(int recno,int c)
{
    //this function takes input "c" and checks whether this input is in the "recno" or not
    int j,k,x,y;
    if(recno<4){k=0;}
    if(recno>3&&recno<7){k=1;}
    if(recno>6){k=2;}
    if(recno%3==1){j=0;}
    if(recno%3==2){j=1;}
    if(recno%3==0){j=2;}
    x=c/65536;
    y=c%65536;
    if((x>=(50+j*200))&&x<=((50+(j+1)*200))&&(y>=(50+k*200))&&(y<=(50+(k+1)*200))){return 1;}
    else {return 0;}
}






bool checkInputValidity(int **quantumTicTacToe,int index1,int index2,int chance)
{//To check validity of the moves selected by player if(invalid) it doesn't allow player to select them
    for(int i=1;quantumTicTacToe[index1][i]!=0;i++)
        {
            for(int j=1;quantumTicTacToe[index2][j]!=0;j++)
                {

                if((quantumTicTacToe[index1][i]==quantumTicTacToe[index2][j])&&((quantumTicTacToe[index1][i]/10)==(chance%2+1)))
                {return 0;}

                }
        }

    return 1;
}





void displayInput(int **quantumTicTacToe,int clickval1,int i)
{
    //this function forms the small rectangles and circles to be placed at the given
    //input place by the player.rectangles for player 1 and circles for player2.
for(int j=1;j<10;j++)
    {
        if(rectangleCheck(j,clickval1))
        {
            for(int k=1;k<10;k++)
                {
                    if(quantumTicTacToe[j][k]==0)
                        {

                            if(i%2==0)
                                {
                                if(k<6)
                                    {
                                    Rectangle small(70+((j-1)%3)*200+(k-1)*40,75+(yCoordinate(j)-1)*200,35,40);
                                    small.setColor(COLOR(0,205,0));
                                    small.setFill();
                                    small.imprint();
                                    Text player1(70+((j-1)%3)*200+(k-1)*40,75+(yCoordinate(j)-1)*200,(i+2)/2);
                                    player1.imprint();//displays the turn number of the player in the small rectangle
                                    }
                                if(k>5)
                                    {
                                    Rectangle small(70+((j-1)%3)*200+160,75+(yCoordinate(j)-1)*200+(k-5)*37.5,40,35);
                                    small.setColor(COLOR(0,205,0));
                                    small.setFill();
                                    small.imprint();
                                    Text player1(70+((j-1)%3)*200+160,75+(yCoordinate(j)-1)*200+(k-5)*37.5,(i+2)/2);
                                    player1.imprint();//displays the turn number of the player in the small rectangle
                                    }


                            quantumTicTacToe[j][k]=(10*(i%2+1)+(i/2)+1);//assigning tensplace to player number and the unitdigitsplace to player turn number.
                            //"j" denotes the rectangle number.
                            return;
                                }

                            if(i%2==1)
                                {
                                if(k<6)
                                    {
                                    Circle small(70+((j-1)%3)*200+(k-1)*40,75+(yCoordinate(j)-1)*200,17);
                                    small.setColor(COLOR(0,150,200));
                                    small.setFill();
                                    small.imprint();
                                    Text player2(70+((j-1)%3)*200+(k-1)*40,75+(yCoordinate(j)-1)*200,(i+1)/2);
                                    player2.imprint();//displays the turn number of the player in the small circle
                                    }
                                if(k>5)
                                    {
                                    Circle small(70+((j-1)%3)*200+160,75+(yCoordinate(j)-1)*200+(k-5)*37.5,17);
                                    small.setColor(COLOR(0,150,200));
                                    small.setFill();
                                    small.imprint();
                                    Text player2(70+((j-1)%3)*200+160,75+(yCoordinate(j)-1)*200+(k-5)*37.5,(i+1)/2);
                                    player2.imprint();//displays the turn number of the player in the small circle
                                    }

                            quantumTicTacToe[j][k]=(10*(i%2+1)+(i/2)+1);//assigning tensplace to player number and the unitdigitsplace to player turn number.
                            //"j" denotes the rectangle number.
                            return;
                                }
                        }
                }
        }
    }
}







void printBackground()
{
    //clears the chatbox
    Rectangle r(800,250,200,40);
    r.setColor(COLOR(255,255,200));
    r.setFill();
    r.imprint();
    return;
}


void smallCircle(int a, int b,int c)
{
    //Inorder to create nodes when circuit is formed.
    Circle node(a,b,5);
    node.setColor(COLOR(255,c,255));
    node.setFill();
    node.imprint();
    return;
}



bool checkCircuit(int ** quantumTicTacToe,int input1,int input2,int previnput1,step s[],int A[],int &n)
{//Main concept of game.Checks whether a circuit is formed in the last step or not

    int i=1;int index=input1;int j=0;int m=n;n++;

    if (input1==input2)
        {A[m]=input1;
        return 1;
        }


    if (quantumTicTacToe[input1][2]==0)
        {

       n--; return false;//returns this when circuit is not formed
        }

    for (i=1;quantumTicTacToe[input1][i]!=0;i++)
        {
        j=0;
        while (s[j].value!=0)
            {
            if (s[j].value==quantumTicTacToe[input1][i])
                {
                if ((s[j].block1==input1)&&(s[j].block2!=previnput1))
                    {index=s[j].block2;}
                else  if ((s[j].block1!=previnput1)&&(s[j].block2==input1))
                    {index=s[j].block1;}
                else
                    {j++;break;}


                if (checkCircuit(quantumTicTacToe,index,input2,input1,s,A,n))
                    {A[m]=input1;
                    return 1 ;
                    }

                }
            j++;
            }
        }
        n--;return false;

}




void collapse(int **quantumTicTacToe,int chosenvalue,step s[],int collapsevalue)
{
    int k=0;quantumTicTacToe[chosenvalue][0]=collapsevalue;
    for(int j=1;quantumTicTacToe[chosenvalue][j]!=0;j++)
        {
        k=0;
        while (s[k].value!=0)
            {
            if(s[k].value==quantumTicTacToe[chosenvalue][j])
                {
                if(s[k].block1==chosenvalue)
                    {
                        if (quantumTicTacToe[s[k].block2][0]==0)
                            {
                            collapsevalue=(s[k].value/10);
                            collapse(quantumTicTacToe,s[k].block2,s,collapsevalue);
                            }
                        else {break;}
                    }
                else if (s[k].block2==chosenvalue)
                    {
                        if (quantumTicTacToe[s[k].block1][0]==0)
                            {
                            collapsevalue=(s[k].value/10);
                            collapse(quantumTicTacToe,s[k].block1,s,collapsevalue);
                            }
                        else {break;}

                    }

                }
            k++;
            }
        }
    return ;
}



int checkWin(int **quantumTicTacToe,int &pointsofplayer1,int &pointsofplayer2)
{
    int condition=0;int S[10],possibility=0;pointsofplayer1=0;pointsofplayer2=0;

    //checks which player wins the game
    //returns 0 if game is drawn
    //returns 1 if player 1 wins the game
    //returns 2 if player 2 wins the game
    //else returns -1.
	if (quantumTicTacToe[1][0] == quantumTicTacToe[2][0] && quantumTicTacToe[2][0] == quantumTicTacToe[3][0]&&quantumTicTacToe[1][0]==1)

		{pointsofplayer1++;}
	if (quantumTicTacToe[4][0] == quantumTicTacToe[5][0] && quantumTicTacToe[5][0] == quantumTicTacToe[6][0]&&quantumTicTacToe[4][0]==1)

		{pointsofplayer1++;}
	if (quantumTicTacToe[7][0] == quantumTicTacToe[8][0] && quantumTicTacToe[8][0] == quantumTicTacToe[9][0]&&quantumTicTacToe[7][0]==1)

        {pointsofplayer1++;}
	if (quantumTicTacToe[1][0] == quantumTicTacToe[4][0] && quantumTicTacToe[4][0] == quantumTicTacToe[7][0]&&quantumTicTacToe[1][0]==1)

		{pointsofplayer1++;}
	if (quantumTicTacToe[2][0] == quantumTicTacToe[5][0] && quantumTicTacToe[5][0] == quantumTicTacToe[8][0]&&quantumTicTacToe[5][0]==1)

		{pointsofplayer1++;}
	if (quantumTicTacToe[3][0] == quantumTicTacToe[6][0] && quantumTicTacToe[6][0] == quantumTicTacToe[9][0]&&quantumTicTacToe[3][0]==1)

		{pointsofplayer1++;}
	if (quantumTicTacToe[1][0] == quantumTicTacToe[5][0] && quantumTicTacToe[5][0] == quantumTicTacToe[9][0]&&quantumTicTacToe[1][0]==1)

		{pointsofplayer1++;}
	if (quantumTicTacToe[3][0] == quantumTicTacToe[5][0] && quantumTicTacToe[5][0] == quantumTicTacToe[7][0]&&quantumTicTacToe[3][0]==1)

		{pointsofplayer1++;}






    if (quantumTicTacToe[1][0] == quantumTicTacToe[2][0] && quantumTicTacToe[2][0] == quantumTicTacToe[3][0]&&quantumTicTacToe[1][0]==2)

		{pointsofplayer2++;}
	if (quantumTicTacToe[4][0] == quantumTicTacToe[5][0] && quantumTicTacToe[5][0] == quantumTicTacToe[6][0]&&quantumTicTacToe[4][0]==2)

		{pointsofplayer2++;}
	if (quantumTicTacToe[7][0] == quantumTicTacToe[8][0] && quantumTicTacToe[8][0] == quantumTicTacToe[9][0]&&quantumTicTacToe[7][0]==2)

        {pointsofplayer2++;}
	if (quantumTicTacToe[1][0] == quantumTicTacToe[4][0] && quantumTicTacToe[4][0] == quantumTicTacToe[7][0]&&quantumTicTacToe[1][0]==2)

		{pointsofplayer2++;}
	if (quantumTicTacToe[2][0] == quantumTicTacToe[5][0] && quantumTicTacToe[5][0] == quantumTicTacToe[8][0]&&quantumTicTacToe[5][0]==2)

		{pointsofplayer2++;}
	if (quantumTicTacToe[3][0] == quantumTicTacToe[6][0] && quantumTicTacToe[6][0] == quantumTicTacToe[9][0]&&quantumTicTacToe[3][0]==2)

		{pointsofplayer2++;}
	if (quantumTicTacToe[1][0] == quantumTicTacToe[5][0] && quantumTicTacToe[5][0] == quantumTicTacToe[9][0]&&quantumTicTacToe[1][0]==2)

		{pointsofplayer2++;}
	if (quantumTicTacToe[3][0] == quantumTicTacToe[5][0] && quantumTicTacToe[5][0] == quantumTicTacToe[7][0]&&quantumTicTacToe[3][0]==2)

		{pointsofplayer2++;}



    if((pointsofplayer1==pointsofplayer2)&&(pointsofplayer1!=0))
        {
        printBackground();
        Text winner(800,250,"GAME DRAW")  ;
        winner.setColor(COLOR(0,210,0));
        winner.imprint();
        return 10;
        }


    if((pointsofplayer2==0)&&(pointsofplayer1==0))
        {
        for(int draw=1;draw<10;draw++)
            {
            if(quantumTicTacToe[draw][0]==0)
                {
                S[possibility]=draw;
                possibility++;
                }
            else
                {condition++;}//checks unwanted endings of the game
            }



        if(condition==9)
            {
            printBackground();
            Text winner(800,250,"GAME DRAW")  ;
            winner.setColor(COLOR(0,210,0));
            winner.imprint();
            return 10;
            }

        if(condition==7)
            {
            if(quantumTicTacToe[S[0]][1]/10==1)
                {
                printBackground();
                Text winner(800,250,"GAME DRAW")  ;
                winner.setColor(COLOR(210,0,0));
                winner.imprint();
                return 10;
                }
            }


        if(condition==8)
            {
            if(quantumTicTacToe[S[0]][1]/10==0)
                {
                printBackground();
                Text winner(800,250,"GAME DRAW")  ;
                winner.setColor(COLOR(210,0,0));
                winner.imprint();
                return 10;
                }
            }

        if(condition==6)
            {
            for(int k=0;k<possibility;k++)
                {
                if((quantumTicTacToe[S[k]][1]/10==1)&&(quantumTicTacToe[S[k]][2]/10==1))
                {return S[k];}
                }
            }


        if(condition==5)
            {
            for(int k=0;k<possibility;k++)
                {
                if((quantumTicTacToe[S[k]][1]/10==1)&&(quantumTicTacToe[S[k]][2]/10==1)&&(quantumTicTacToe[S[k]][3]/10==1))
                {return S[k];}
                }
            }
        }

    if(pointsofplayer1>pointsofplayer2)
        {
        printBackground();
        Text winner(800,250,"PLAYER         WINS!!!")  ;
        winner.setColor(COLOR(210,0,0));
        winner.imprint();


        Rectangle turn1(800,250,30,30);
            turn1.setColor(COLOR(0,205,0));
            turn1.setFill();
            turn1.imprint();

            Text turnname(800,250,"1");
            turnname.imprint();
        return 11;

        }

   if(pointsofplayer1<pointsofplayer2)
        {
        printBackground();
        Text winner(800,250,"PLAYER         WINS!!!")  ;
        winner.setColor(COLOR(0,0,210));
        winner.imprint();
         Circle turn2(800,250,15);
            turn2.setColor(COLOR(0,150,200));
            turn2.setFill();
            turn2.imprint();

            Text turnname(800,250,"2");
            turnname.imprint();
        return 12;

        }

        return -1;
}

int newGame()
{
    int a,x,y;
    for(;;)
        {
        a=getClick();
        x=a/65536;
        y=a%65536;

        if(x<875&&x>725&&y>55&&y<85){return 1;}

        else continue;
        }

}

