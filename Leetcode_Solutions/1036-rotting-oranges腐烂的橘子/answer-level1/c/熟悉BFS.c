### 解题思路
本题目的是熟悉BFS基本思路：

注意仔细读题，对几种场景下合法性、结果的判定

本质上是从所有2开始，往周边BFS直到污染完毕；

基本的bfs思路不变，剩下的就是想办法刻画结束状态？达不成的情况等；这些用能实现的方式进行实现都可以；

注意queue队列深度，和普通bfs不同，多点bfs深度预留足够；

```
//基本bfs大致思路 其余部分可自行理解 自由实现

q.enqueue(start)

while (!q.empty()) {
    node = q.dequeue();
    
    for each n in nodes.neighbours()
        if (visit[n] is not)
            q.enqueuue(n);

    node = q.dequeue();
}

```



### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX 101
#define CORRUPT 2
#define NORMAL  1
#define EMPTY   0

int step_x[4] = {1, -1, 0, 0};
int step_y[4] = {0, 0, 1, -1};

int visit[MAX][MAX] = {0};

struct Node {
    int x;
    int y;
};

struct my_queue {
    struct Node nodes[2 * MAX];
    int head;
    int tail;
    int size;
};

void en_queue(struct my_queue *q, int x, int y)
{
    q->nodes[q->tail].x = x;
    q->nodes[q->tail].y = y;
    q->tail = (q->tail + 1) % q->size;
}

struct Node de_queue(struct my_queue *q)
{
    struct Node node;
    node.x = q->nodes[q->head].x;
    node.y = q->nodes[q->head].y;
    q->head = (q->head + 1) % q->size;
    return node;
}

int is_queue_empty(struct my_queue *q)
{
    return q->head == q->tail;
}

void init_my_queue(struct my_queue *q)
{
    memset(q->nodes, 0x0, sizeof(int) * 2 * MAX);
    q->head = 0;
    q->tail = 0;
    q->size = 2 * MAX;
}

void move_queue(struct my_queue *old_queue, struct my_queue *new_queue)
{
    struct Node node;
    while (!is_queue_empty(old_queue)) {
        node = de_queue(old_queue);
        en_queue(new_queue, node.x, node.y);
    }
}

int count_in_map(int **grid, int gridSize, int *gridColSize, int target_value)
{
    int cnt = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] ==  target_value)
                cnt++;
        }
    }
    return cnt;
}

int enqueue_corrupt_orange(int **grid, int gridSize, int *gridColSize, struct my_queue *begin_queue)
{
    int cnt = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] != CORRUPT)
                continue;
            en_queue(begin_queue, i, j);
            visit[i][j] = 1;
            cnt++;
        }
    }
    return cnt;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL)
        return 0;

    int one_cnt = count_in_map(grid, gridSize, gridColSize, NORMAL);
    if (one_cnt == 0)
        return 0;
    
    memset(visit, 0x0, sizeof(visit));
    struct my_queue cur_queue;
    init_my_queue(&cur_queue);
    struct my_queue next_queue;
    init_my_queue(&next_queue);

    if (enqueue_corrupt_orange(grid, gridSize, gridColSize, &cur_queue) == 0)
        return -1;

    int corrupt_time = 0;
    struct Node node;
    while (!is_queue_empty(&cur_queue)) {
        node = de_queue(&cur_queue);

        for (int i = 0; i < 4; i++) {
            int new_x = node.x + step_x[i];
            int new_y = node.y + step_y[i];
            if (new_x < 0 || new_x >= gridSize || new_y < 0 || new_y >= gridColSize[new_x])
                continue;
            if (visit[new_x][new_y])
                continue;
            if (grid[new_x][new_y] == NORMAL) {
                en_queue(&next_queue, new_x, new_y);
                visit[new_x][new_y] = 1;
                one_cnt--;
            }
        }

        if (is_queue_empty(&cur_queue) && !is_queue_empty(&next_queue)) {
            move_queue(&next_queue, &cur_queue);
            corrupt_time++;
        }
    }

    if (one_cnt) {
        return -1;
    } else {
        return corrupt_time;
    }
}
```