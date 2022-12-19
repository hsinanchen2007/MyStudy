### 解题思路
1. 遍历(i,j)如果为1，则建一个队列，将(i,j)加入队列
2. 遍历队列，判断四连通方向是否在矩阵范围内，如果为1，则加入队列
3. 遍历队列直至为空，得到一个面积
4. 建一个search和矩阵同大小，如果节点遍历过，则在1、2、3的队列处理中略过

### 代码

```c
typedef struct queNode {
    int row;
    int col;
    struct queNode *next;
} QNODE;

void addQue(QNODE **head, QNODE **last, int x, int y, char **search) {
    QNODE *node = (QNODE*)malloc(sizeof(QNODE));
    node->row = x;
    node->col = y;
    node->next = NULL;

    if (*head == NULL) {
        *head = *last = node;
    } else {
        (*last)->next = node;
        *last = node;
    }
    search[x][y] = 1;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    if (!grid || gridSize == 0 || !gridColSize || gridColSize[0] == 0) return 0;

    char **search = (char**)malloc(sizeof(char*) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        search[i] = (char*)malloc(gridColSize[0]);
        (void)memset(search[i], 0, gridColSize[0]);
    }

    int max = 0;
    int fourDir[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 0 || search[i][j]) continue;

            QNODE *head = NULL, *last = NULL;
            addQue(&head, &last, i, j, search);

            QNODE *cur = head, *tmp;
            int area = 0;
            while (cur) {
                area++;
                for (int k = 0; k < 4; k++) {
                    int tmpx = cur->row + fourDir[k][0];
                    int tmpy = cur->col + fourDir[k][1];
                    if (tmpx < 0 || tmpx >= gridSize || tmpy < 0 || tmpy >= gridColSize[0]) continue;
                    if (search[tmpx][tmpy] || grid[tmpx][tmpy] == 0) continue;
                    addQue(&head, &last, tmpx, tmpy, search);
                }
                tmp = cur->next;
                free(cur);
                cur = tmp;
            }
            max = fmax(max, area);
        }
    }
    return max;
}
```