### 解题思路
遍历：
1. 新腐烂的橘子，数值等于上一代腐烂的数值+1，第一代腐烂为初始值2
2. 每次发现当代腐烂值周边有1（未腐烂），则将其腐烂为下一代腐烂值，并计数
3. 一次遍历没有新增腐烂，则循环结束
4. 看看是否有未腐烂的。否则循环次数为分钟数。

BFS：
1. 建一个链表，遍历一遍数组，把值为2的坐标加入链表节点。
2. 遍历取链表（队列），判断该节点上下左右有没有1，有则改为2，层次数+1，加入链表尾
3. 直到链表为空。此时遍历数组看看是否有1则返回-1；否则返回广度的层次数。


### 代码
BFS
```c
typedef struct myListNode {
    int x;
    int y;
    int level;
    struct myListNode *next;
} MYLISTNODE;

void enQue(MYLISTNODE **qtail, int x, int y, int l) {
    MYLISTNODE *node = (MYLISTNODE*)malloc(sizeof(MYLISTNODE));
    MYLISTNODE *que = *qtail;

    node->x = x;
    node->y = y;
    node->level = l;
    node->next = NULL;

    if (que) {
        que->next = node;
    }
    *qtail = node;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int i;
    int j;
    int level = 0;

    MYLISTNODE *que = NULL;
    MYLISTNODE *last = NULL;

    for (i=0; i<gridSize; i++) {
        for (j=0; j<gridColSize[0]; j++) {
            if (grid[i][j] == 2) {
                enQue(&last, j, i, level);
                if (!que) que=last;
            }
        }
    }

    int x[] = {-1, 0, 1, 0};
    int y[] = {0, -1, 0, 1};

    while (que) {
        if (que->level != level) level++;

        int i;
        for (i=0; i<sizeof(x)/sizeof(x[0]); i++) {
            int tmpx = que->x + x[i];
            int tmpy = que->y + y[i];

            if (tmpx < 0 || tmpx >= gridColSize[0] || tmpy < 0 || tmpy >= gridSize) continue;

            if (grid[tmpy][tmpx] == 1) {
                enQue(&last, tmpx, tmpy, level+1);
                grid[tmpy][tmpx] = 2;
            }
        }
        que = que->next;

    }

    for (i=0; i<gridSize; i++) {
        for (j=0; j<gridColSize[0]; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return level;
}
```

遍历
```c
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int i;
    int j;
    int count = 0;
    int min = 0;
    int curRot = 2;
    int nextRot;

    while (1) {
        count = 0;
        nextRot = curRot+1;
        for (i=0; i<gridSize; i++) {
            for (j=0; j<gridColSize[0]; j++) {
                if (grid[i][j] == curRot) {
                    if (i>0 && grid[i-1][j] == 1) {
                        grid[i-1][j] = nextRot;
                        count++;
                    }
                    if (i<gridSize-1 && grid[i+1][j] == 1) {
                        grid[i+1][j] = nextRot;
                        count++;
                    }
                    if (j>0 && grid[i][j-1] == 1) {
                        grid[i][j-1] = nextRot;
                        count++;
                    }
                    if (j<gridColSize[0]-1 && grid[i][j+1] == 1) {
                        grid[i][j+1] = nextRot;
                        count++;
                    }
                }
            }
        }
        if (count == 0) break;
        min++;
        curRot = nextRot;
    }

    for (i=0; i<gridSize; i++) {
        for (j=0; j<gridColSize[0]; j++) {
            if (grid[i][j] == 1) return -1;
        }
    }
    return min;
}
```