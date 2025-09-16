#include <bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt", "r", stdin)
#define OUTPUT freopen("output.txt", "w", stdout)
#define ll long long

char ar[1001][1001];
char dir[1001][1001];
bool vis[1001][1001];
vector<char> path;
int n, m;

bool is_Valid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m) return false;
    if (vis[x][y] || ar[x][y] == '#') return false;
    return true;
}

bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (ar[a][b] == 'B')
        {
            // reconstruct path
            while (ar[a][b] != 'A')
            {
                path.push_back(dir[a][b]);
                if(path.back() == 'L') b++;
				if(path.back() == 'R') b--;
				if(path.back() == 'U') a++;
				if(path.back() == 'D') a--;
                if(a==x and b==y)break;
            }
             
            return true;
        }

        if (is_Valid(a, b + 1)) dir[a][b + 1] = 'R', q.push({a, b + 1}), vis[a][b + 1] = true;
        if (is_Valid(a, b - 1)) dir[a][b - 1] = 'L', q.push({a, b - 1}), vis[a][b - 1] = true;
        if (is_Valid(a + 1, b)) dir[a + 1][b] = 'D', q.push({a + 1, b}), vis[a + 1][b] = true;
        if (is_Valid(a - 1, b)) dir[a - 1][b] = 'U', q.push({a - 1, b}), vis[a - 1][b] = true;
    }
    return false;
}

void solve()
{
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ar[i][j];
            vis[i][j] = false;
            dir[i][j] = 0;
            if (ar[i][j] == 'A') { x = i; y = j; }
        }
    }

    if (bfs(x, y))
    {
        cout << "YES" << endl;
         reverse(path.begin(),path.end());
         cout<<path.size()<<endl;
        for (char c : path) cout << c;
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
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
