#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int maze[N][N] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}};
int sx = 0, sy = 0;
int ex = 4, ey = 4;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int visited[N][N] = {0};
vector<pair<int, int>> recursionPath;
vector<pair<int, int>> dfsPath;
vector<pair<int, int>> bfsPath;

bool valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool mazeRecursion(int x, int y, vector<pair<int, int>> &path, int visited[][N])
{
    if (!valid(x, y) || maze[x][y] == 1 || visited[x][y])
        return false;

    visited[x][y] = 1;
    path.push_back({x, y});

    if (x == ex && y == ey)
        return true;

    for (int i = 0; i < 4; i++)
    {
        if (mazeRecursion(x + dx[i], y + dy[i], path, visited))
            return true;
    }

    visited[x][y] = 0;
    path.pop_back();
    return false;
}

bool mazeDfs(vector<pair<int, int>> &path)
{
    struct State
    {
        int x;
        int y;
        int dir;//保存方向信息
    };

    int visited[N][N] = {0};
    stack<State> st;
    path.clear();

    if (!valid(sx, sy) || !valid(ex, ey) || maze[sx][sy] == 1 || maze[ex][ey] == 1)
        return false;

    st.push({sx, sy, 0});
    visited[sx][sy] = 1;
    path.push_back({sx, sy});

    while (!st.empty())
    {
        State &cur = st.top();
        if (cur.x == ex && cur.y == ey)
            return true;

        if (cur.dir == 4)
        {
            visited[cur.x][cur.y] = 0;
            st.pop();
            path.pop_back();
            if (!st.empty())
                st.top().dir++;
            continue;
        }

        int nx = cur.x + dx[cur.dir];
        int ny = cur.y + dy[cur.dir];
        if (!valid(nx, ny) || maze[nx][ny] == 1 || visited[nx][ny])
        {
            cur.dir++;
            continue;
        }

        visited[nx][ny] = 1;
        st.push({nx, ny, 0});
        path.push_back({nx, ny});
    }

    return false;
}

bool mazeBfs(vector<pair<int, int>> &path)
{
    int visited[N][N] = {0};
    pair<int, int> parent[N][N];
    queue<pair<int, int>> q;
    path.clear();

    if (!valid(sx, sy) || !valid(ex, ey) || maze[sx][sy] == 1 || maze[ex][ey] == 1)
        return false;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            parent[i][j] = {-1, -1};
        }
    }

    q.push({sx, sy});
    visited[sx][sy] = 1;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.first == ex && cur.second == ey)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (!valid(nx, ny) || maze[nx][ny] == 1 || visited[nx][ny])
                continue;

            visited[nx][ny] = 1;
            parent[nx][ny] = cur;
            q.push({nx, ny});
        }
    }

    if (!visited[ex][ey])
        return false;

    for (pair<int, int> cur = {ex, ey}; cur.first != -1; cur = parent[cur.first][cur.second])
    {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return true;
}

void printPath(const char *title, const vector<pair<int, int>> &path)
{
    printf("%s", title);
    printf("(%d,%d)", path[0].first, path[0].second);
    for (size_t i = 1; i < path.size(); i++)
    {
        printf("->(%d,%d)", path[i].first, path[i].second);
    }
    printf("  步数:%d\n", (int)path.size() - 1);
}

int main()
{

    mazeRecursion(sx, sy, recursionPath, visited);
    mazeDfs(dfsPath);
    mazeBfs(bfsPath);

    printPath("递归: ", recursionPath);
    printPath("DFS:", dfsPath);
    printPath("BFS:", bfsPath);

    return 0;
}
