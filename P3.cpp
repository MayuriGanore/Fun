#include<iostream>
using namespace std;
class Edge
{
    public:
    int src;
    int dest;
    int weight;
    int dist;
    int id;
    void Display(Edge A[],int e,int v);
    void Logic(Edge A[],int e,int v,int source);
};
void Edge::Display(Edge A[],int e,int v)
{
    cout<<"\nID\tSource\tDest\tWeight\tDist\n";
    for(int i=0;i<e;i++)
    {
        cout<<"\n"<<A[i].id<<"\t"<<A[i].src<<"\t"<<A[i].dest<<"\t"<<A[i].weight<<"\t"<<A[i].dist<<"\n";
    }
}
void Edge::Logic(Edge A[],int e,int v,int source)
{
    int start;
    int end;
    int flag=0;
    for(int i=0;i<v;i++)
    {
        flag=0;
        for(int j=0;j<e;j++)
        {
            start=A[j].src;
            end=A[j].dest;
            if((A[end].dist>A[start].dist+A[j].weight)&&(A[start].dist!=999))
            {
                A[end].dist=A[start].dist+A[j].weight;
                flag=1;
            }
        }
        cout<<"\nPrinting the Values\n";
        cout<<"\nIteration No. "<<i+1;
        cout<<"\nID\tDistance\n";
        for(int k=1;k<=v;k++)
        {
            cout<<k<<"\t"<<A[k].dist<<"\n";
        }
        if(flag==0)
        {
            break;
        }
    }
}
int main()
{
    int v,e;
    cout<<"Enter the No. of Vertices:";
    cin>>v;
    cout<<"\nEnter the No. of Edges:";
    cin>>e;
    int source;
    cout<<"\nEnter the Source Vertex:";
    cin>>source;
    Edge A[e];
    for(int i=0;i<e;i++)
    {
        cout<<"Enter the Source of Edge "<<i+1<<" : ";
        cin>>A[i].src;
        cout<<"\nEnter the Destination of Edge "<<i+1<<" : ";
        cin>>A[i].dest;
        cout<<"\nEnter the Weight of Edge "<<i+1<<" : ";
        cin>>A[i].weight;
        A[i].dist=999;
        A[i].id=i+1;
    }
    A[source].dist=0;
    Edge obj;
    obj.Display(A,e,v);
    obj.Logic(A,e,v,source);
    return 0;
}
/*
output
Enter the No. of Vertices:6

Enter the No. of Edges:9

Enter the Source Vertex:1
Enter the Source of Edge 1 : 1

Enter the Destination of Edge 1 : 2

Enter the Weight of Edge 1 : 6
Enter the Source of Edge 2 : 1

Enter the Destination of Edge 2 : 3

Enter the Weight of Edge 2 : 4
Enter the Source of Edge 3 : 1

Enter the Destination of Edge 3 : 4

Enter the Weight of Edge 3 : 5
Enter the Source of Edge 4 : 2

Enter the Destination of Edge 4 : 5

Enter the Weight of Edge 4 : -1
Enter the Source of Edge 5 : 3

Enter the Destination of Edge 5 : 2

Enter the Weight of Edge 5 : -2
Enter the Source of Edge 6 : 4

Enter the Destination of Edge 6 : 3

Enter the Weight of Edge 6 : -2
Enter the Source of Edge 7 : 3

Enter the Destination of Edge 7 : 5

Enter the Weight of Edge 7 : 3
Enter the Source of Edge 8 : 4

Enter the Destination of Edge 8 : 6

Enter the Weight of Edge 8 : -1
Enter the Source of Edge 9 : 5

Enter the Destination of Edge 9 : 6

Enter the Weight of Edge 9 : 3

ID      Source  Dest    Weight  Dist

1       1       2       6       999

2       1       3       4       0

3       1       4       5       999

4       2       5       -1      999

5       3       2       -2      999

6       4       3       -2      999

7       3       5       3       999

8       4       6       -1      999

9       5       6       3       999

Printing the Values

Iteration No. 1
ID      Distance
1       0
2       2
3       3
4       5
5       5
6       4

Printing the Values

Iteration No. 2
ID      Distance
1       0
2       1
3       3
4       5
5       1
6       4

Printing the Values

Iteration No. 3
ID      Distance
1       0
2       1
3       3
4       5
5       0
6       3

Printing the Values

Iteration No. 4
ID      Distance
1       0
2       1
3       3
4       5
5       0
6       3
*/