// 			   -- THE MEMORY GAME --

/*  This game puts your memory to the test with the classic 'Find the pair'
    game.
    -The objective of the game is to memorize the given grid in specified
     time and later on enter the location of a pair of symbols.

    # The rules and regulations for the game are as follows:
      -locations of elements are to be written in row no.<space>column no.
	format.
      -correct response earns score of +1.
      -wrong response gives upto 2 attempts and then terminates the game.

*/

#include <iostream.h>
#include <conio.h>
#include <stdlib.h>              //for random function
#include <dos.h>                 //for delay function
#include <process.h>

void head(void);
void game_code(void);
void load(void);
int check(char a[4][4],char);


void main()
{ clrscr();
  int choice;
  do
  {
   head();
   cout<<"\n\t"<<"MAIN MENU";
   cout<<"\n\t"<<"1. Play Game";
   cout<<"\n\t"<<"2. Credits";
   cout<<"\n\t"<<"3. Exit"<<"\n\n\t->";
   cin>>choice;

   switch(choice)
    {  case 1: clrscr();
	       game_code();
	       cout<<"\n"<<"Press enter to return to main menu.";
	       getch();
	       clrscr();
	       break;

       case 2: clrscr();
	       head();
	       cout<<"\tThis game titled 'The Memory Game' has been jointly developed by,\n ";
	       cout<<"\n\t\t"<<"- Anish Patil";
	       cout<<"\n\t\t"<<"- Shashwat Debnath";
	       cout<<"\n\t\t"<<"- S.Roshan Sameer";
	       cout<<"\n\t\t"<<"- Paras Khekre";

	       cout<<"\n\n\t"<<"Press enter to return to main menu";
	       getch();
	       clrscr();
	       break;

       case 3: exit(0);

       default:clrscr();
	       cout<<"Enter valid Input !";
	       continue;
    }

  }while(1);

 }



  void head(void)
  { cout<<"\t\t\t"<<"  -- THE MEMORY GAME -- "<<"\n\n";
  }



  void game_code(void)
  {
   clrscr();
   randomize();

   int i,j,m,n,p,q,score=0,attempt=0;
   char arr[4][4],choice,rndnum;
   int b[4][4];
   char symbol[]={1,2,3,4,5,6,14,15};


   for(i=0;i<4;i++)
    for(j=0;j<4;j++)
     { arr[i][j]=0;
       b[i][j]=0;
     }

   load();                                      //function for introduction


   for(i=0;i<4;i++)
    {
      j=0;
      while(j<4)
       { rndnum=symbol[random(8)];      //gets random symbol from symbol array
	 if(check(arr,rndnum))          //function call
	    arr[i][j]=rndnum;
	 else
	    continue;
	 j++;

       }

    }


   head();
   cout<<"\n\n\t"<<" _______________"<<"\n";
   for(i=0;i<4;i++)
   { cout<<"\t| ";
     for(j=0;j<4;j++)
       cout<<arr[i][j]<<" | ";
     cout<<"\n\t"<<"|___|___|___|___|"<<"\n";
   }


   cout<<"\n You have 15 seconds to memorize the table !";
   delay(15000);
   clrscr();


   while(attempt<3)
     {
	head();
	cout<<"Enter coordinates as - rowno.<space>column no. ;"<<"\n";

	cout<<"\n\n\t"<<" _______________\n";
	for(i=0;i<4;i++)
	{ cout<<"\t| ";
	  for(j=0;j<4;j++)
	  { if(b[i][j]==1)
	       cout<<arr[i][j]<<" | ";

	    else cout<<"  | ";

	  }
	  cout<<"\n"<<"\t|___|___|___|___|\n";
	}

	int flag=0;
	for(i=0;i<4;i++)
	 for(j=0;j<4;j++)
	  { if(b[i][j]==0)
	      flag=1;
	  }
	if(flag==1);
	else
	  break;

	cout<<"\n"<<"Enter location of element:";
	cin>>m>>n;
	cout<<"Enter location of its pair:";
	cin>>p>>q;

	clrscr();

	if((m==p)&&(n==q))
	  {  head();
	     cout<<"\n\n"<<"Enter two DIFFERENT locations!\n ";
	     delay(2000);
	     clrscr();
	     continue;
	  }
	if((m>4)||(n>4)||(p>4)||(q>4))
	  { head();
	    cout<<"\n\n"<<"Enter coordinates within grid limit!\n";
	    delay(2000);
	    clrscr();
	    continue;
	  }

	if((b[m-1][n-1]==1)||(b[p-1][q-1]==1))
	  { head();
	    cout<<"\n\n"<<"You have already entered this location value.";
	    delay(2000);
	    clrscr();
	    continue;
	  }


	head();
	cout<<"\n";
	cout<<"\n\n\t"<<" _______________\n";
	for(i=0;i<4;i++)
	{ cout<<"\t| ";
	  for(j=0;j<4;j++)
	  { if((((m-1)==i)&&((n-1)==j))||(((p-1)==i)&&((q-1)==j)))
	     { if((arr[m-1][n-1]==arr[p-1][q-1])&&!((m==p)&&(n==q)))
		  b[i][j]=1;
	       cout<<arr[i][j]<<" | ";
	     }
	    else
	     { if(b[i][j]==1)
		 cout<<arr[i][j]<<" | ";
	       else cout<<"  | ";
	     }
	  }
	    cout<<"\n"<<"\t|___|___|___|___|\n";
	}



	if(arr[m-1][n-1]==arr[p-1][q-1])
	  { cout<<"\n"<<"GOOD ! Now next pair\n";
	    score++;
	  }
	else
	  {  if(attempt<2)
	      { cout<<"\nWrong Answer !! Try once more.";
		attempt++;
	      }
	     else
	      { cout<<"\nThat was your last attempt. Terminating!";
		attempt++;
		delay(2000);
	      }
	  }
	delay(2000);
	clrscr();

     }

    head();
    cout<<"\n\n"<<"Your score was : "<<score;
    if(score==8)
      cout<<"\nYou are the master of memory ! ! !";
    cout<<"\n\n\t"<<" _______________\n";

	for(i=0;i<4;i++)
	{ cout<<"\t| ";
	  for(j=0;j<4;j++)
	  { if(b[i][j]==1)
	       cout<<arr[i][j]<<" | ";

	    else cout<<"  | ";

	  }
	  cout<<"\n"<<"\t|___|___|___|___|\n";
	}

 }
  void load(void)
  { head();
    cout<<"\n\n"<<"Loading  ";
    for(int r=0;r<3;r++)
    { delay(350);
      cout<<". ";
      delay(350);
    }
    clrscr();

    head();
    cout<<"\n\n"<<" # The rules and regulations for the game are as follows:\n";
    cout<<"\n  -locations of elements to be written as row no.<space>column no.";
    cout<<"\n  -correct response earns score of +1.";
    cout<<"\n  -wrong response gives upto 2 attempts and then terminates the game.";
    char ch;
    cout<<"\n\n\nPress enter to continue.";
    getch();
    clrscr();

    head();
    cout<<"\n"<<"The following row and column numbers indicate element's position : ";
    cout<<"\n\n"<<"\t  (column no.) -> \n"<<"\t    1   2   3   4"<<"\n";
    cout<<"(row no.)"<<"  _______________"<<"\n";
    for(int i=0;i<4;i++)
    { cout<<"\t"<<i+1<<" | ";
     for(int j=0;j<4;j++)
       cout<<"  | ";
     cout<<"\n\t"<<"  |___|___|___|___|"<<"\n";
    }
    cout<<"\n\n"<<"Press Enter to continue:";
    getch();
    clrscr();
    return;
  }


  int check(char a[4][4],char x)
  { int count=0;
    for(int i=0;i<4;i++)
     for(int j=0;j<4;j++)
       { if(a[i][j]==x)
	count++;
       }

    if((count==0)||(count==1))
      return 1;
    else
      return 0;
  }
