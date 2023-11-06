#include <iostream>
using namespace std;
class Bag
{
public:
    double w;
    double p;
    int flag;
    double ratio;
    double fraction;
    int id;
    void Print(Bag A[], int n);
    void Sort(Bag A[], int n);
    void Logic(Bag A[], int n, double capacity);
};
void Bag::Sort(Bag A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j].ratio < A[j + 1].ratio)
            {
                Bag temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
void Bag::Print(Bag A[], int n)
{
    cout << "\nID\tProfit\tWeight\tRatio\tFraction\n";
    for (int i = 0; i < n; i++)
    {
        cout << A[i].id << "\t" << A[i].p << "\t" << A[i].w << "\t" << A[i].ratio << "\t\t" << A[i].fraction << "\n";
    }
}
void Bag::Logic(Bag A[], int n, double capacity)
{
    double TW = 0;
    double TP = 0;
    int i = 0;
    while (1)
    {
        if (TW < capacity)
        {
            if (A[i].w <= (capacity - TW) && A[i].flag == 0)
            {
                A[i].flag = 1;
                A[i].fraction = 1;
                TW += A[i].w;
                TP += A[i].p;
            }
            else
            {
                A[i].flag = 1;
                A[i].fraction = ((capacity - TW) / A[i].w);
                TW += A[i].w*A[i].fraction;
                TP += A[i].p*A[i].fraction;
            }
        }
        else
        {
            break;
        }
        i++;
    }
    cout<<"Total Profit is:"<<TP<<"\n";
}
int main()
{
    int n;
    cout << "Enter the No. of Objects:";
    cin >> n;
    Bag A[n];
    double capacity;
    cout << "\nEnter the Capacity of Bag:\n";
    cin >> capacity;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Weight of " << i + 1 << " object:";
        cin >> A[i].w;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Profit of " << i + 1 << " object:";
        cin >> A[i].p;
    }
    for (int i = 0; i < n; i++)
    {
        A[i].fraction = 0;
        A[i].flag = 0;
        A[i].id = i + 1;
        A[i].ratio = A[i].p / A[i].w;
    }
    Bag obj;
    obj.Print(A, n);
    obj.Sort(A, n);
    obj.Print(A, n);
    obj.Logic(A, n, capacity);
    obj.Print(A, n);
    return 0;
}
/*
output:
Enter the No. of Objects:7

Enter the Capacity of Bag:
15
Enter the Weight of 1 object:2
Enter the Weight of 2 object:3
Enter the Weight of 3 object:5
Enter the Weight of 4 object:7
Enter the Weight of 5 object:1
Enter the Weight of 6 object:4
Enter the Weight of 7 object:1
Enter the Profit of 1 object:10
Enter the Profit of 2 object:5
Enter the Profit of 3 object:15
Enter the Profit of 4 object:7
Enter the Profit of 5 object:6
Enter the Profit of 6 object:18
Enter the Profit of 7 object:3

ID      Profit  Weight  Ratio   Fraction
1       10      2       5               0
2       5       3       1.66667         0
3       15      5       3               0
4       7       7       1               0
5       6       1       6               0
6       18      4       4.5             0
7       3       1       3               0

ID      Profit  Weight  Ratio   Fraction
5       6       1       6               0
1       10      2       5               0
6       18      4       4.5             0
3       15      5       3               0
7       3       1       3               0
2       5       3       1.66667         0
4       7       7       1               0
Total Profit is:55.3333

ID      Profit  Weight  Ratio   Fraction
5       6       1       6               1
1       10      2       5               1
6       18      4       4.5             1
3       15      5       3               1
7       3       1       3               1
2       5       3       1.66667         0.666667
4       7       7       1               0
*/