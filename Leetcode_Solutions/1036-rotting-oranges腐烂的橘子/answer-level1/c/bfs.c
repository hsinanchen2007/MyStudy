```
/*
 * @lc app=leetcode.cn id=994 lang=c
 *
 * [994] N 天后的牢房
 *
 * https://leetcode-cn.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Easy (46.77%)
 * Total Accepted:    8.2K
 * Total Submissions: 17.4K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * 在给定的网格中，每个单元格可以有以下三个值之一：
 *
 *
 * 值 0 代表空单元格；
 * 值 1 代表新鲜橘子；
 * 值 2 代表腐烂的橘子。
 *
 *
 * 每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
 *
 * 返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：[[2,1,1],[1,1,0],[0,1,1]]
 * 输出：4
 *
 *
 * 示例 2：
 *
 * 输入：[[2,1,1],[0,1,1],[1,0,1]]
 * 输出：-1
 * 解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
 *
 *
 * 示例 3：
 *
 * 输入：[[0,2]]
 * 输出：0
 * 解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * grid[i][j] 仅为 0、1 或 2
 *
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100
struct MyQueue {
    int item[MAX][3];
    int front;
    int rear;
};

struct MyQueue *CreateQueue(void)
{
    struct MyQueue *q = malloc(sizeof(*q));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool IsEmpty(struct MyQueue *q)
{
    return q->front == -1;
}

void EnQueue(struct MyQueue *q, int x, int y, int step)
{
    q->item[++q->rear][0] = x;
    q->item[q->rear][1] = y;
    q->item[q->rear][2] = step;

    if (q->front == -1) {
        q->front = 0;
    }
}

void DeQueue(struct MyQueue *q, int *px, int *py, int *pstep)
{
    *px = q->item[q->front][0];
    *py = q->item[q->front][1];
    *pstep = q->item[q->front][2];
    q->front++;

    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
}

int orangesRotting(int** grid, int gridSize, int* gridColSize)
{
    int i, j;
    int count = 0;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    struct MyQueue *q = CreateQueue();
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 2) {
                EnQueue(q, i, j, 0);
            } else if (grid[i][j] == 1) {
                count++;
            }
        }
    }

    if (count == 0) {
        free(q);
        return 0;
    }

    int curx, cury, curstep;
    int nx, ny;
    int res = 0;
    while (!IsEmpty(q)) {
        DeQueue(q, &curx, &cury, &curstep);
        for (i = 0; i < 4; i++) {
            nx = curx + dir[i][0];
            ny = cury + dir[i][1];
            if (nx >= gridSize || nx < 0 || ny >= gridColSize[0] || ny < 0) {
                continue;
            }

            if (grid[nx][ny] == 0 || grid[nx][ny] == 2) {
                continue;
            }

            grid[nx][ny] = 2;
            EnQueue(q, nx, ny, curstep + 1);
            count--;
        }

        if (count == 0) {
            res = curstep + 1;
            break;
        }
    }

    if (count > 0) {
        return -1;
    }
    return res;
}

```
