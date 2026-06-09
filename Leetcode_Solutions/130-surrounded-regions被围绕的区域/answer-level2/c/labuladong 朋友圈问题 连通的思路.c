### 解题思路
此处撰写解题思路

### 代码

```c
int *g_arr;
int g_count;
int *g_size;

int Find(int x)
{
    while (g_arr[x] != x) {
        g_arr[x] = g_arr[g_arr[x]]; // 将x的parent 指向其爷爷，使得层级减少
        x = g_arr[x];
    }

    return x;
}

bool IsConnected(int x, int y)
{
    return Find(x) == Find(y);
}

void UnionEle(int x, int y)
{
    int xparent = Find(x);
    int yparent = Find(y);
    if (xparent == yparent) {
        return;
    }

    if (g_size[xparent] > g_size[yparent]) {
        g_arr[yparent] = xparent;
        g_size[xparent] += g_size[yparent];
    } else {
        g_arr[xparent] = yparent;
        g_size[yparent] += g_size[xparent];
    }
    g_count--; // 不同的圈子个数减少1个
}

// 遍历board[row][col] 周围的四个节点，如果是'O'，则将其与中心点连通，记住，先遍历中心点左边的点，因为这个点的parent是dummy，如果这个点是‘O’的话，那么连通后中心点的parent也是dummy。
void SearchNeighbor(char **borad, int colsize, int g_arr[], int row, int col)
{
    int arridxCenter = row * colsize + col;
    
    int xrow = row;
    int ycol = col - 1;
    int arridx = xrow * colsize + ycol;
    if (borad[xrow][ycol] == 'O') {
        UnionEle(arridx, arridxCenter);
    }

    xrow = row - 1;
    ycol = col;
    arridx = xrow * colsize + ycol;
    if (borad[xrow][ycol] == 'O') {
        UnionEle(arridx, arridxCenter);
    }

    xrow = row;
    ycol = col + 1;
    arridx = xrow * colsize + ycol;
    if (borad[xrow][ycol] == 'O') {
        UnionEle(arridx, arridxCenter);
    }

    xrow = row + 1;
    ycol = col;
    arridx = xrow * colsize + ycol;
    if (borad[xrow][ycol] == 'O') {
        UnionEle(arridx, arridxCenter);
    }
}

void solve(char **board, int boardSize, int* boardColSize)
{
    int idx;
    int row;
    int col;
    int colsize = boardColSize[0];
    int dummy = boardSize * colsize; // dummy为二维数组元素个数+1

    if (board == NULL || boardSize == 0 || boardColSize == NULL || colsize == 0) {
        return ;
    }
    g_count = boardSize * colsize + 1;

    g_arr = (int *)malloc(sizeof(int) * g_count);
    if (g_arr == NULL) {
        return ;
    }
    memset(g_arr, 0, sizeof(int) * g_count);

    g_size = (int *)malloc(sizeof(int) * g_count);
    if (g_size == NULL) {
        return ;
    }
    memset(g_size, 0, sizeof(int) * g_count);

    for(int i = 0; i <= boardSize * colsize; i++) {
        g_arr[i] = i;
        g_size[i] = 1;
    }

    // parent是 一维数组，保存二维数组每一个元素的父亲；第一行 和 最后一行节点的parent 是dummy；第一列和最后一列的parent是dummy
    // 第一行
    for(col = 0; col < colsize; col++) {
        g_arr[col] = dummy;
        g_size[dummy]++;
    }

    // 最后一行
    row = (boardSize - 1) * colsize;
    for(col = 0; col < colsize; col++) {
        g_arr[row + col] = dummy;
        g_size[dummy]++;
    }

    for(row = 1; row < boardSize - 1; row++) {
        idx = row * colsize;
        g_arr[idx] = dummy; // 第一列
        g_arr[idx + colsize - 1] = dummy; // 最后一列
    }

    for(row = 1; row < boardSize - 1; row++) {
        idx = row * colsize;
        for (col = 1; col < colsize - 1; col++) {
            // 遍历board[row][col]周围的四个元素
            if (board[row][col] == 'O') {
                SearchNeighbor(board, colsize, g_arr, row, col);
            }
        }
    }

    // 将二维数组board不与dummy连通的点设为X
    for(row = 1; row < boardSize - 1; row++) {
        idx = row * colsize;
        for (col = 1; col < colsize - 1; col++) {
            // 遍历board[row][col]周围的四个元素
            if (!IsConnected(idx + col, dummy)) {
                board[row][col] = 'X';
            }
        }
    }

}

```