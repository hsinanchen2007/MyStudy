### 解题思路
此处撰写解题思路

### 代码

```c

struct node {
    int x;
    int y;
};
struct node *qHead;
int qStart;
int qEnd = 0;
int qLen = 0;

struct node *PopQueue(struct node *qHead, int *start, int *end) {
    if (*start < *end) {
        (*start)++;
        return qHead + *start - 1;
    }  
    return NULL;
}
struct node *PushQueue(struct node *qHead, struct node *node, int *end, int len) {
    if (*end < qLen) {
        memcpy(qHead + *end, node, sizeof(struct node));
        (*end)++;
        return qHead + *end;
    } 
    return NULL;
}
int bfs(int **grid, int col, int line, struct node *point) {
    int x = point->x;
    int y = point->y;
    struct node tmp;
    int flag = 0;
    if(x < col - 1 && grid[x + 1][y] == 0) {
        grid[x + 1][y] = grid[x][y] + 1;
        tmp.x = x + 1;
        tmp.y = y;
        (void)PushQueue(qHead, &tmp, &qEnd, qLen);
        flag = 1;
    } 
    if (y < line - 1 && grid[x][y + 1] == 0) {
        grid[x][y + 1] = grid[x][y] + 1;
        tmp.x = x;
        tmp.y = y + 1;
        (void)PushQueue(qHead, &tmp, &qEnd, qLen);
        flag = 1;
    } 
    if(x > 0 && grid[x - 1][y] == 0) {
        grid[x - 1][y] = grid[x][y] + 1;
        tmp.x = x - 1;
        tmp.y = y;
        (void)PushQueue(qHead, &tmp, &qEnd, qLen);
        flag = 1;
    } 
    if(y > 0 && grid[x][y - 1] == 0) {
        grid[x][y - 1] = grid[x][y] + 1;
        tmp.x = x;
        tmp.y = y - 1;
        (void)PushQueue(qHead, &tmp, &qEnd, qLen);
        flag = 1;
    } 
    if (flag == 0) {
        return -1;
    }
    return 0;
}

int maxDistance(int** grid, int gridSize, int* gridColSize){
    qHead = (struct node*)malloc(sizeof(struct node) * gridSize * *gridColSize);
    qLen = gridSize * gridSize;
    qStart = 0;
    qEnd = 0;

    int i;
    int j;
    int land = 0;
    struct node node;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                land++;
                node.x = i;
                node.y = j;
                (void)PushQueue(qHead, &node, &qEnd, gridSize);
            }
        }
    }
    if(land == gridSize * *gridColSize || land == 0) {
        return -1;
    }
    int *s = (int *)malloc(sizeof(int) * land);
    memset(s, 0, sizeof(int) * land);
    struct node *tmp = PopQueue(qHead, &qStart, &qEnd);
    int ret;
    i = 0;
    int min;
    while (tmp != NULL) {
        if (i < land) {
            s[i]++;
        }
        ret = bfs(grid, gridSize, gridSize, tmp);
        if (ret != 0) {
            if (qStart >= qEnd) {

                min = grid[tmp->x][tmp->y] - 1;
                break;
            }
            tmp = PopQueue(qHead, &qStart, &qEnd);
            continue;
        }
        if (qStart >= qEnd) {
            min = grid[tmp->x][tmp->y];
            break;
        }
        tmp = PopQueue(qHead, &qStart, &qEnd);
        i++;
    }

    free(s);
    free(qHead);
    s = NULL;
    qHead = NULL;
    return min;
}
```