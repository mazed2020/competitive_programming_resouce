#include <bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt", "r", stdin)
#define OUTPUT freopen("output.txt", "w", stdout)
int n, m;
vector<vector<bool>> vis(1000,vector<bool>(1000,0));
vector<int> h = {1, -1, 0, 0};
vector<int> v = {0, 0, 1, -1};

void dfs(int row, int col)
{
    vis[row][col] = true;
    for (int i = 0; i < 4; i++)
    {
        int x = row + h[i];
        int y   = col + v[i];
        if (0 <= x && x < n && 0 <= y && y < m && !vis[x][y])
            dfs(x, y);
    }
}

void solve()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {

        cin >> n >> m;
        int row=0;
        int col =0;
        

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char x;
                cin >> x;
                 
                vis[i][j] = (x == '#');
            }
        }
        int cnt = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // cout<<vis[i][j]<<" ";
                if (!vis[i][j] and )
                {
                    dfs(i, j);
                    cnt++;
                }
            }
            // cout<<endl;
        }
        cout << cnt << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // INPUT;
    // OUTPUT;

    solve();

    return 0;
}