### 解题思路
思路和题解差不多，两个节点间使用BFS求最短距离，唯一要注意的是C实现的时候不要用realloc，不然会严重超时。

### 代码

```c
typedef struct {
    int x;
    int y;
    int h;
} Node;

int cmp(const void *a, const void *b)
{
    Node *aa = (Node *)a;
    Node *bb = (Node *)b;
    return (aa->h > bb->h);
}

int cutOffTree(int **forest, int forestSize, int *forestColSize)
{
    int i, j, starth;
    int k = 0;
    Node *list = malloc(sizeof(Node) * forestSize * forestColSize[0]);
    char **flag = malloc(sizeof(char *) * forestSize);
    for (i = 0; i < forestSize; i++) {
        for (j = 0; j < forestColSize[i]; j++) {
            list[k].x = i;
            list[k].y = j;
            list[k].h = forest[i][j];
            k++;
        }
        flag[i] = malloc(forestColSize[i]);
        memset(flag[i], 0, forestColSize[i]);
    }
    qsort(list, k, sizeof(Node), cmp);
    for (i = 0; i < k; i++) {
        if (list[i].h > 1) {
            starth = i;
            break;
        }
    }
    Node *queue = 0;
    int queueNum = 0;
    int curIdx = 0;
    queueNum++;
    queue = malloc(sizeof(Node) * 10000);
    queue[queueNum - 1].x = 0;
    queue[queueNum - 1].y = 0;
    flag[0][0] = 1;
    Node *cur;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int minStep = 0;
    int nextIdx = 0;

    while (curIdx < queueNum) {
        Node tmp;
        for (i = 0; i < 4; i++) {
            tmp.x = queue[curIdx].x + dx[i];
            tmp.y = queue[curIdx].y + dy[i];
            if (tmp.x >= 0 && tmp.x < forestSize && tmp.y >= 0 && tmp.y < forestColSize[0]) {
                if (flag[tmp.x][tmp.y] == 0 && forest[tmp.x][tmp.y] >= 1) {
                    queueNum++;
                    flag[tmp.x][tmp.y] = 1; 
                    memcpy(&queue[queueNum - 1], &tmp, sizeof(tmp));
                }
            }
        }
        curIdx++;
    }

    for (i = 0; i < forestSize; i++) {
        for (j = 0; j < forestColSize[i]; j++) {
            if (forest[i][j] > 1 && flag[i][j] == 0) {
                free(queue);
                queue = 0;
                for (j = 0; j < forestSize; j++) {
                    free(flag[j]);
                }
                free(list);
                return -1;
            }
        }
    }

    Node preNode;
    preNode.x = 0;
    preNode.y = 0;
    // queue = malloc(sizeof(Node) * 10000);

    for (i = starth; i < k; i++) {
        if (preNode.x == list[i].x && preNode.y == list[i].y) {
            continue;
        }
        for (j = 0; j < forestSize; j++) {
            memset(flag[j], 0, forestColSize[j]);
        }

        queueNum = 1;
        queue[queueNum - 1].x = preNode.x;
        queue[queueNum - 1].y = preNode.y;
        queue[queueNum - 1].h = 0;
        flag[preNode.x][preNode.y] = 1;

        int findTar = 0;
        curIdx = 0;
        while (curIdx < queueNum) {
            Node tmp;
            for (j = 0; j < 4; j++) {
                tmp.x = queue[curIdx].x + dx[j];
                tmp.y = queue[curIdx].y + dy[j];
                tmp.h = queue[curIdx].h + 1;
                if (tmp.x >= 0 && tmp.x < forestSize && tmp.y >= 0 && tmp.y < forestColSize[0]) {
                    if (flag[tmp.x][tmp.y] == 0 && forest[tmp.x][tmp.y] >= 1) {
                        if (tmp.x == list[i].x && tmp.y == list[i].y) {
                            minStep += tmp.h;
                            findTar = 1;
                            break;
                        }
                        queueNum++;
                        flag[tmp.x][tmp.y] = 1;
                        memcpy(&queue[queueNum - 1], &tmp, sizeof(tmp));
                    }
                }
            }
            if (findTar) {
                break;
            }
            curIdx++;
        }

        preNode.x = list[i].x;
        preNode.y = list[i].y;
    }
    free(queue);
    for (j = 0; j < forestSize; j++) {
        free(flag[j]);
    }
    free(list);

    return minStep;
}
```