### 解题思路
每个海洋点，做广度遍历，找到距离最近的陆地，可以计算出距离。
答案是上面步骤中每次求得的距离中的最大值

执行结果：通过 显示详情
执行用时 :2572 ms, 在所有 C 提交中击败了5.31%的用户
内存消耗 :373.3 MB, 在所有 C 提交中击败了7.24%的用户

### 代码

```c

typedef struct queNode {
    int i;
    int j;
    struct queNode *next;
} QUENODE;

void add2Que(QUENODE **head, QUENODE **last, int i, int j) {
    QUENODE *tmp = (QUENODE *)malloc(sizeof(QUENODE));
    tmp->i = i;
    tmp->j = j;
    tmp->next = NULL;

    if (*head == NULL) {
        *head = *last = tmp;
    } else {
        (*last)->next = tmp;
        *last = tmp;
    }
}

int processOcean(int** grid, int gridSize, int* gridColSize, int i, int j) {
    char visited[gridSize][gridColSize[0]];
    (void)memset(visited, 0, gridSize * gridColSize[0]);

    QUENODE *head = NULL;
    QUENODE *last = NULL;
    add2Que(&head, &last, i, j);
    visited[i][j] = 1;
    //int dis = bfs(grid, visited, gridSize, gridColSize, &head, &last);

    QUENODE *tmp;
    int oceani = i;
    int oceanj = j;
    bool landFound = false;
    int tmpi, tmpj;

    int fourDir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    while (head) {
        for (int k = 0; k < 4; k++) {
            tmpi = head->i + fourDir[k][0];
            tmpj = head->j + fourDir[k][1];

            if (tmpi < 0 || tmpi >= gridSize || tmpj < 0 || tmpj >= gridColSize[0]) continue;
            if (visited[tmpi][tmpj]) continue;

            if (grid[tmpi][tmpj] == 1) {
                landFound = true;
                break;
            } else {
                add2Que(&head, &last, tmpi, tmpj);
                visited[tmpi][tmpj] = 1;
            }
        }
        if (landFound) break;
        tmp = head->next;
        free(head);
        head = tmp;
    }

    while (head) {
        tmp = head->next;
        free(head);
        head = tmp;
    }

    int dis = (landFound) ? (abs(tmpi - oceani) + abs(tmpj - oceanj)) : -1;

    return dis;
}

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int dis = -1;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 0) {
                int ret = processOcean(grid, gridSize, gridColSize, i, j);
                dis = fmax(dis, ret);           
            }
        }
    }

    return dis;
}
```