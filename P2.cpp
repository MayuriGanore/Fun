#include<iostream>
using namespace std;
class Bag{
    public:
    int weight;
    int profit;
    int id;
    int flag;
    int Max(int a,int b);
    void Logic(int n,int max_profit,Bag A[]);
};
int Bag::Max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
void Bag::Logic(int n,int max_profit,Bag A[])
{
    int Mat[n+1][max_profit+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=max_profit;j++)
        {
            if(i==0 || j==0)
            Mat[i][j]=0;
            else if(A[i-1].weight<=j)
            Mat[i][j]=Max((A[i-1].profit+Mat[i-1][j-A[i-1].weight]),Mat[i-1][j]);
            else
            Mat[i][j]=Mat[i-1][j];
        }
    }
    cout<<"\nPrinting Matrix:\n";
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=max_profit;j++)
        {
            cout<<Mat[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\nMax Pofit is:"<<Mat[n][max_profit];
    int RP=Mat[n][max_profit];
    int Output[n];
    int i=n;
    int j=max_profit;
    while(i>0)
    {
        if(Mat[i][j]==Mat[i][j-1])
        {
            Output[i-1]=0;
            j--;
        }
        else
        {
            if(Mat[i][j]==Mat[i-1][j])
            {
                Output[i-1]=0;
                i--;
            }
            else
            {
                Output[i-1]=1;
                A[i-1].flag=1;
                RP-=A[i-1].profit;
                i--;
                for(int m=max_profit;m>=0;m--)
                {
                    if(Mat[i][m]==RP)
                    {
                        j=m;
                    }
                }
                if(RP==0)
                {
                    break;
                }
            }
        }
    }
    while(i>0)
    {
        Output[i-1]=0;
        i--;
    }
    cout<<"\nOutput Included are:\n";
    for(int z=0;z<n;z++)
    {
        if(A[z].flag==1)
        {
            cout<<"Object "<<A[z].id<<" is included"<<endl;
        }
        else
        {
            cout<<"Object "<<A[z].id<<" is not included"<<endl;
        }
    }
}
int main()
{
    int n;
    cout<<"\nEnter the No. of Objects:";
    cin>>n;
    int max_profit;
    cout<<"\nEnter the Maximum Weight:";
    cin>>max_profit;
    Bag A[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter the Profit of "<<i+1<<" Object:";
        cin>>A[i].profit;
        cout<<"\nEnter the Weight of "<<i+1<<" Object:";
        cin>>A[i].weight;
        A[i].flag=0;
        A[i].id=i+1;
    }
    cout<<"\nId\tProfit\tWeight\tFlag\n";
    for(int i=0;i<n;i++)
    {
        cout<<A[i].id<<"\t"<<A[i].profit<<"\t"<<A[i].weight<<"\t"<<A[i].flag<<"\n";
    }
    Bag obj;
    obj.Logic(n,max_profit,A);
    return 0;
}
/*
output:
Enter the No. of Objects:4

Enter the Maximum Weight:8

Enter the Profit of 1 Object:1

Enter the Weight of 1 Object:2

Enter the Profit of 2 Object:2

Enter the Weight of 2 Object:3

Enter the Profit of 3 Object:5

Enter the Weight of 3 Object:4

Enter the Profit of 4 Object:6

Enter the Weight of 4 Object:5

Id      Profit  Weight  Flag
1       1       2       0
2       2       3       0
3       5       4       0
4       6       5       0

Printing Matrix:
0       0       0       0       0       0       0       0       0
0       0       1       1       1       1       1       1       1
0       0       1       2       2       3       3       3       3
0       0       1       2       5       5       6       7       7
0       0       1       2       5       6       6       7       8

Max Pofit is:8
Output Included are:
Object 1 is not included
Object 2 is included
Object 3 is not included
Object 4 is included
*/ 
