#include<fstream>
#include<iostream>
using namespace std;

int n, m, s[200][2], is, js, ib, jb, ready, kf, b[20][20];
char a[20][20];
int dl[5] = {0, -1, 0, 1, 0};
int dc[5] = {0, 0, 1, 0, -1};
ifstream f("soarece1.in");
ofstream g("soarece1.out");
void citire()
{
    f >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            f >> a[i][j];
            if(a[i][j] == 'B')
                ib = i, jb = j;
            else if(a[i][j] == 'S')
                is = i, js = j;
        }

    }
}

void scrie()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            g << b[i][j] << " ";
        g << endl;
    }
}

int valid(int k, int lin, int col)
{
    if(a[lin][col] == '#')
        return 0;
    for(int i = 1; i < k; i++)
    {
        if(s[i][0] == lin && s[i][1] == col)
            return 0;
    }
    return 1;
}

void bkt(int k, int lin, int col)
{
    if(ready)
        return;
    if(lin == 0 || col == 0 || lin > n || col > m)
        return;
    if(lin == ib && col == jb)
    {
        ready = 1;
        s[k][0] = lin;
        s[k][1] = col;

        kf = k;
        return;
    }
    else
    {
        int i;
        s[k][0] = lin;
        s[k][1] = col;
        for(i = 1; i <= 4; i++)
        {
            int coloana = col + dc[i];
            int linia = lin + dl[i];
            if(valid(k, linia, coloana))
                bkt(k + 1, linia, coloana);

        }
    }
}

int main()
{
    citire();
    cerr << is << " " << js << " " << ib << " " << jb << endl;
    bkt(1, is, js);
    cerr << kf << endl;
    for(int i = 1; i <= kf; i++)
        b[s[i][0]][s[i][1]] = i;
    scrie();
    f.close();
    g.close();
    return 0;
}
