#include <fstream>
#include <vector>
using namespace std;
int main()
{
    ifstream fin("bst.in");
    ofstream fout("bst.out");
    int n;
    fin >> n;
    
    //vector<long long> m(n);
    int* m = new int[n];
    fin >> m[0];
    //vector<long long> up(n);
    //long long* up = new long long[n];
    //long long* down = new long long[n];
    vector<pair<long long, long long>> borders(n);
    
    borders[0].second = (long long)INT_MAX + 1;
    borders[0].first = INT_MIN;
    
    int i = 1;
    char c;
    int p;
    while (i < n) {

        fin >> m[i] >> p >> c;

        int parent = --p;
        if (c == 'L') {
            borders[i].first = borders[parent].first;
            borders[i].second = m[parent];
        }
        else {
            borders[i].second = borders[parent].second;
            borders[i].first = m[parent];
        }
        if (!((long long)m[i] < borders[i].second && (long long)m[i] >= borders[i].first)) {
            fout << "NO";
            delete[] m;
            return 0;
        }
        i++;
    }
    delete[] m;
    fout << "YES";
    return 0;
}
