#define SIZE 101

bool vis[SIZE];
bool g_matrix[SIZE][SIZE];
bool g_flag;

double Calc(int n, int start, int target, int t, int count, double pro)
{
    if (vis[start]) {
        return 0;
    }
    if (count > t) {
        return 0;
    }
    
    vis[start] = true;
    int i;
    double ret = 0;
    int de = 0;
    for (i = 1; i <= n; ++i) {
        if (!vis[i] && g_matrix[start][i]) {
            ++de;
        }
    }
    if (start == target) {
        g_flag = true;
        if (count < t && de != 0) {
            return 0;
        }
        return pro;
    }
    if (de == 0) {
        return 0;
    }

    double nextPro = 1.0 / de * pro;

    for (i = 1; i <= n; ++i) {
        if (!vis[i] && g_matrix[start][i]) {
            ret = Calc(n, i, target, t, count + 1, nextPro);
            if (g_flag) {
                return ret;
            }
        }
    }
    vis[start] = false;
    return 0;
}

double frogPosition(int n, int** edges, int edgesSize, int* edgesColSize, int t, int target){
    int i;
    memset(g_matrix, 0, sizeof(g_matrix));
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < edgesSize; ++i) {
        g_matrix[edges[i][0]][edges[i][1]] = true;
        g_matrix[edges[i][1]][edges[i][0]] = true;
    }
    g_flag = false;
    return Calc(n, 1, target, t, 0, 1);
}
