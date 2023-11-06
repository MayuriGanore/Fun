#include<iostream>
using namespace std;
int IsSafe(int row,int col,int Mat[][10],int n)
{
    for(int i=0;i<row;i++)
    {
        if(Mat[i][col]==1)
        return 0;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(Mat[i][j]==1)
        return 0;
    }
    for(int i=row,j=col;i>=0 &&j<n;i--,j++)
    {
        if(Mat[i][j]==1)
        return 0;
    }
    return 1;
}
int SolveQueen(int row,int Mat[][10],int n)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<Mat[i][j]<<"\t";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return 0;
    }
    int flag=0;
    for(int k=0;k<n;k++)
    {
        if(IsSafe(row,k,Mat,n)==1)
        {
            Mat[row][k]=1;
            flag=(SolveQueen(row+1,Mat,n)||flag);
            Mat[row][k]=0;
        }
    }
    return flag;
}
int main()
{
    int n;
    cout<<"\nEnter the No. of Queens:";
    cin>>n;
    int Mat[10][10]={0};
    if(SolveQueen(0,Mat,n)==0)
    {
        cout<<"\nSolution Exists!!";
    }
    else
    {
        cout<<"\nSolution Does not Exists!!";
    }
    return 0;
}
/*
output:
Enter the No. of Queens:4
0       1       0       0
0       0       0       1
1       0       0       0
0       0       1       0

0       0       1       0
1       0       0       0
0       0       0       1
0       1       0       0


Solution Exists!!
*/