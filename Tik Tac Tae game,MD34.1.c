#include<stdio.h>
#include<stdbool.h>
int isWin(int a[][4],int n)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i][1]==a[i][2] && a[i][2]==a[i][3] && a[i][1]!=-1)
        {
            return a[i][1];
        }
    }
    for(int j=1;j<=n;j++)
    {
        if(a[1][j]==a[2][j] && a[2][j]==a[3][j] && a[1][j]!=-1)
        {
            return a[1][j];
        }
    }

    if(a[1][1]==a[2][2] && a[2][2]==a[3][3] && a[1][1]!=-1)
    {
        return a[1][1];
    }

     if(a[1][3]==a[2][2] && a[2][2]==a[3][1] && a[1][3]!=-1)
    {
        return a[1][3];
    }

    return -1;
}
void printcell(int a[][4],int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           if(a[i][j]==-1) printf(" ");
           if(a[i][j]==1)printf("X");
           if(a[i][j]==2)printf("o");
           if(j<n)printf("\t  |\t");
        }
        printf("\n");
        if(i<n)printf("_______________________________________");
        printf("\n\n");
    }
}
void printWin(int a[][4],int n,int who) //who=2
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {

           if(a[i][j]==who)
           {
               if(a[i][j]==1)printf("X");
               else printf("o");
           }
           else
           {
               printf(" ");
           }
           if(j<n)printf("\t  |\t");
        }
        printf("\n");
        if(i<n)printf("_______________________________________");
        printf("\n\n");
    }
}
int main()
{
    int n=3;
    int a[4][4];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=-1;
        }
    }
    bool player1=true;
    bool player2=false;
    while(true)
    {
        printcell(a,n);
      if(player1==true)
      {
          //kaj
          //man 1
          int r,c;
          Flag:

          printf("player 1 Turn (X), Enter Row and Colum:: ");
          scanf("%d %d",&r,&c);
          if(a[r][c]!=-1)
          {
              printf("Invalid cell\n");
              goto Flag;
          }
          a[r][c]=1;
          player1=false;
          player2=true;
      }
      else
      {
          //kaj
          //man 2
          int r,c;
          Flag2:
          printf("player 2 Turn (o), Enter Row and Colum:: ");
          scanf("%d %d",&r,&c);
          if(a[r][c]!=-1)
          {
              printf("Invalid cell\n");
              goto Flag2;
          }
          a[r][c]=2;
          player2=false;
          player1=true;
      }
      //check who wins
      if(isWin(a,n)==1)
      {
          printf("Player 1 Won!\n");
          printWin(a,n,1);
          //printcell(a,n);
          break;
      }
      else if(isWin(a,n)==2)
      {
          printf("Player 2 Won\n");
          printWin(a,n,2);
          //printcell(a,n);
          break;
      }

    }
   // printcell(a,n);

    return 0;
}
