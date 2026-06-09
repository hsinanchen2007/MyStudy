    按照题解翻译成C而已
1 - DFS
```
void Dfs(char** grid, int rows, int cols,int x, int y)
{
    grid[x][y] = '0'; // 将遍历过的相连位置标记为0
    if (x - 1 >= 0 && grid[x-1][y] == '1') 
        Dfs(grid, rows, cols, x - 1, y);

    if (x + 1 < rows && grid[x+1][y] == '1') 
        Dfs(grid, rows, cols, x + 1, y);

    if (y - 1 >= 0 && grid[x][y-1] == '1') 
        Dfs(grid, rows, cols, x, y - 1);

    if (y + 1 < cols && grid[x][y+1] == '1') 
        Dfs(grid, rows, cols, x, y + 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int islandnums = 0;

    if (grid == NULL || gridSize == 0 || *gridColSize == 0) {
        return 0;
    }

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == '1') {
                islandnums++;
                Dfs(grid, gridSize, gridColSize[0], i, j);
            }
        }
    }
    return islandnums;
}
```
2 - BFS
```
typedef struct _Node{
    int x;
    int y;
}Node;

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int islandnums = 0;

    if (grid == NULL || gridSize == 0 || gridColSize[0] == 0) {
        return 0;
    }

    Node * q = (Node *)malloc(sizeof(Node) * gridSize * gridColSize[0]);
    memset(q, 0, sizeof(Node) * gridSize * gridColSize[0]); 
    Node cur;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == '1') {
                islandnums++;
                grid[i][j] == '0';
                int front = 0;
                q[front].x = i;
                q[front++].y = j;
                while(front != 0) {
                    cur = q[--front];
                    if (cur.x - 1 >= 0 && grid[cur.x - 1][cur.y] == '1') {
                        grid[cur.x - 1][cur.y] = '0';
                        q[front].x = cur.x - 1;
                        q[front++].y = cur.y;
                    }
                    if (cur.x + 1 < gridSize && grid[cur.x + 1][cur.y] == '1') {
                        grid[cur.x + 1][cur.y] = '0';
                        q[front].x = cur.x + 1;
                        q[front++].y = cur.y;
                    }
                    if (cur.y - 1 >= 0 && grid[cur.x][cur.y - 1] == '1') {
                        grid[cur.x][cur.y - 1] = '0';
                        q[front].x = cur.x;
                        q[front++].y = cur.y - 1;
                    }
                    if (cur.y + 1 < gridColSize[0] && grid[cur.x][cur.y + 1] == '1') {
                        grid[cur.x][cur.y + 1] = '0';
                        q[front].x = cur.x;
                        q[front++].y = cur.y + 1;
                    }
                    //printf("%d\n", front);
                }
            }
        }
    }

    free(q);

    return islandnums;
}
```
3 - 并查集
```
int FindRoot(int x, int *parent) 
{
    if (parent[x] != x) {
        parent[x] = FindRoot(parent[x], parent); 
    }
    return parent[x];
}

int UnionRoot(int x, int y, int *parent, int *rank, int count)
{
    int a = FindRoot(x, parent);
    int b = FindRoot(y, parent);

    if (a != b) { // 压缩路径
        if (rank[a] > rank[b]) { // 平衡性优化
            parent[b] = a;
        } else if (rank[a] < rank[b]) {
            parent[a] = b;
        } else {
            parent[b] = a; 
            rank[a] += 1;
        }
        count--;
    }

    return count;
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    if (grid == NULL || gridSize == 0 || gridColSize[0] == 0) {
        return 0;
    }

    int count = 0;
    int parent[gridSize * gridColSize[0]];
    int rank[gridSize * gridColSize[0]];

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == '1') {
                parent[i * gridColSize[0] + j] = i * gridColSize[0] + j;
                count++;
            }
            rank[i * gridColSize[0] + j] = 0;
        }
    }
    //printf("after init:%d\n", count);
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; ++j) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                if (i - 1 >= 0 && grid[i-1][j] == '1') {
                    count = UnionRoot(i * gridColSize[0] + j, (i-1) * gridColSize[0] + j,\
                    parent, rank, count);
                    //printf("union1:%d\n", count);
                }
                if (i + 1 < gridSize && grid[i+1][j] == '1') {
                    count = UnionRoot(i * gridColSize[0] + j, (i+1) * gridColSize[0] + j,\
                    parent, rank, count);
                    //printf("union2:%d\n", count);
                }
                if (j - 1 >= 0 && grid[i][j-1] == '1') {
                    count = UnionRoot(i * gridColSize[0] + j, i * gridColSize[0] + j - 1,\
                    parent, rank, count);
                    //printf("union3:%d\n", count);
                }
                if (j + 1 < gridColSize[0] && grid[i][j+1] == '1') {
                    count = UnionRoot(i * gridColSize[0] + j, i * gridColSize[0] + j + 1,\
                    parent, rank, count);
                    //printf("union4:%d\n", count);
                }
            }
        }
    }

    return count;
}
```
