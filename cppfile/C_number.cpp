#include <iostream>
using namespace std;

//chose:选了哪些数
bool chose[1000001];
//chosed:位置
void dg(int n, int m, int chosed, int last)
{
    if (chosed == m)
    {
        for (int i = 1; i <= n; i++)
        {
            if (chose[i])
            {
                cout << i << ' ';
            }
        }
        cout << endl;
    }
    else
    {
        for (int i = last + 1; i <= n; i++)
        {
            chose[i] = true;
            dg(n, m, chosed + 1, i);
            chose[i] = false;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    dg(n, m, 0, 0);
}