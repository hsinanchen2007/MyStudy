### 解题思路
    之前用细分网格+深搜的方式写过这题，效率不是很高，用并查集的思路写了一遍，大体思路就不写了，看看代码理解一下吧。有疑问可以在评论区留言。

### 代码

```c
inline void InitUnionFind(int* root, char** grid, int gridSize)
{
    int col = gridSize + 1;
    for (int i = 0; i <= gridSize; i++) {
        for (int j = 0; j <= gridSize; j++) {
            int index = i * col + j;
            if (i == 0 || j == 0 || i == gridSize || j == gridSize) {
                root[index] = 0;
            } else {
                root[index] = index;
            }
        }
    }
}

int Find(int* root, int x)
{
    if (x != root[x]) {
        return root[x] = Find(root, root[x]);
    }
    return root[x];
}

void Union(int* root, int x, int y, int* count)
{
    int rootX = Find(root, x);
    int rootY = Find(root, y);
    if (rootX != rootY) {
        root[rootY] = rootX;
    } else {
        (*count)++;
    }
    return;
}

int regionsBySlashes(char ** grid, int gridSize){
    if (!grid || gridSize <= 0) {
        return 0;
    }
    int* root = (int*)malloc(sizeof(int) * (gridSize + 1) * (gridSize + 1));
    InitUnionFind(root, grid, gridSize);
    int col = gridSize + 1;
    int count = 1;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j] == '\\') {
                int index = i * col + j;
                Union(root, index, index + col + 1, &count);
            } else if (grid[i][j] == '/') {
                int index = i * col + j + 1;
                Union(root, index, index + col -1, &count);
            }
        }
    }
    free(root);
    return count;
}


```