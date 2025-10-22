#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;
int main()
{
    ifstream fin("bst.in");
    ofstream fout("bst.out");
    int n;
    fin >> n;
    if (n == 1) {
        fout << "YES";
        return 0;
    }
    int k;
    fin >> k;
    vector<long long> m(n);
    m[0] = k;
    vector<int> p(n);
    vector<char> c(n);
    
    /*for (int i = 0; i < n - 1; i++) {
        fin >> m[i + 1];
        fin >> p[i];
        fin >> c[i];
    }*/
    vector<long long> up(n, 0);
    vector<long long> down(n, 0);

    up[0] = (long long)INT_MAX+1;
    down[0] = INT_MIN;

    int i = 1;
    bool ind = true;
    while (i < n && ind) {

        fin >> m[i];
        fin >> p[i];
        fin >> c[i];

        int parent = p[i]-1;
        if (c[i] == 'L') {
            down[i] = down[parent];
            up[i] = m[parent];
        }
        else if (c[i] == 'R') {
            up[i] = up[parent];
            down[i] = m[parent];
        }
        if (m[i] >= up[i] || m[i] < down[i])
            ind = false;
      
      

        i++;
    }

    if (ind) {
        cout << "YES";
        fout << "YES";
    }
    else {
        cout << "NO";
        fout << "NO";
    }
    return 0;
}