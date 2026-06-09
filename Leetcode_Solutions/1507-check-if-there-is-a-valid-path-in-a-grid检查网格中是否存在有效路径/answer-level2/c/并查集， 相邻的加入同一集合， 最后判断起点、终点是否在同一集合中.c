void InitDsu(int *dsu, int num)
{
    for (int i = 0; i < num; i++) {
        dsu[i] = i;
    }
    return;
}

int FindDsu(int *dsu, int a)
{
    int fa = dsu[a];
    if (fa == a) {
        return fa;
    }
    dsu[a] = FindDsu(dsu, dsu[a]);
    return dsu[a];
}


void MergerDsu(int *dsu, int a, int b)
{
    int fa = FindDsu(dsu, a);
    int fb = FindDsu(dsu, b);
    if (fa == fb) {
        return;
    }
    dsu[fa] = fb;
    return;
}

int g_dirV[4][6][6] = {
    {{1, 0, 1, 0, 1, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 1, 0}, {0, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 1, 0}},
    {{1, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1}, {0, 1, 0, 0, 1, 1}, {0, 1, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}}, 
    {{0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 0, 0}}
};

int g_move[4][2] = {{0 , 1}, {0, -1}, {1, 0}, {-1, 0}};

bool IfConnected(int** grid, int i, int j, int dir, int x, int y)
{
    int cI = grid[i][j];
    int cJ = grid[x][y];
    return 1 == g_dirV[dir][cI - 1][cJ - 1];
}

bool IfValid(int x, int y, int r, int c) {
    return (x >= 0 && x < r && y >= 0 && y < c);
}    

bool hasValidPath(int** grid, int gridSize, int* gridColSize){
    int r = gridSize;
    int c = *gridColSize;
    int num = r * c;
    int dsu[num];
    InitDsu(dsu, num);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < 4; k++) {
                int ni = i + g_move[k][0];
                int nj = j + g_move[k][1];
                if (IfValid(ni, nj, r, c) && IfConnected(grid, i , j, k, ni, nj)) {
                    MergerDsu(dsu, i * c + j, ni * c + nj);
                }
            }
        }
    }
    int fs = FindDsu(dsu, 0);
    int fe = FindDsu(dsu, r * c - 1);

    return fs == fe;
}