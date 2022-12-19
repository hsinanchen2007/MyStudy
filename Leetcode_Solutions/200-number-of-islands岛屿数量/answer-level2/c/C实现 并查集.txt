![image.png](https://pic.leetcode-cn.com/441707b75981a347e32673ca7240baffba8d6b74124ce69a939dadddf30df9e8-image.png)

### 解题思路
并查集，相邻的岛屿合并为一个圈，统计最终圈子个数

### 代码

```c
#define INVALID -2
#define VALID -1

int FindRoot(int x, int *preNode)
{
    int son = x;
    int temp;

    if (preNode[x] == -1) { //根是自身
        return x;
    }

    while (preNode[x] != -1) { //找到root
        x = preNode[x];
    }

    while (son != x) { //路径压缩，每个节点都连接到根节点上，节省查找时间
        temp = preNode[son];
        preNode[son] = x;
        son = temp;
    }

    return x;
}

void UnionRoot(int x, int y, int *preNode)
{
    int a = FindRoot(x, preNode);
    int b = FindRoot(y, preNode);

    if (a != b) {
        preNode[a] = b;
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int size;
    int a, b, c;
    int count = 0;
    int *preNode;

    if (gridSize < 1) {
        return 0;
    }

    size = gridSize * gridColSize[0];
    preNode = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < gridSize; i++) {  //预处理，不能组成岛屿的赋值为-2，方便后续统计
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '0') {
                preNode[i * gridColSize[i] + j] = INVALID;
            } else {
                preNode[i * gridColSize[i] + j] = VALID;
            }
        }
    }

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) { //相邻的1合并到一个岛屿（并查集）
            a = i * gridColSize[0] + j;
            b = a + 1; //a的右节点 
            c = a + gridColSize[0];  //a的下节点           
            if (preNode[a] != INVALID) {
                if ((b < ((i + 1) * gridColSize[0])) && preNode[b] != INVALID) {
                    UnionRoot(a, b, preNode);
                }
                if ((c < size) && preNode[c] != INVALID) {
                    UnionRoot(a, c, preNode);
                }
            } 
        }

    }

    for (int i = 0; i < size; i++) {
        if (preNode[i] == VALID) {
            count++;
        }
    }

    free(preNode);
    return count;
}
```