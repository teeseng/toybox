#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = n; i >= 1; --i)
    {
        for(int j = 1; j < i; ++j)
        {
            if(a[j] > a[j+1])
            {
                cout << j << ' '<< j+1 << endl;
                swap(a[j], a[j+1]);
            }
        }
    }

    return 0;
}
