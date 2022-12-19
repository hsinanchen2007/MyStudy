```
/*
 * @lc app=leetcode.cn id=1162 lang=c
 *
 * [1162] 项目员工II
 *
 * https://leetcode-cn.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (35.60%)
 * Total Accepted:    8K
 * Total Submissions: 20.1K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * 你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1
 * 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。
 *
 * 我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 -
 * x1| + |y0 - y1| 。
 *
 * 如果我们的地图上只有陆地或者海洋，请返回 -1。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：[[1,0,1],[0,0,0],[1,0,1]]
 * 输出：2
 * 解释：
 * 海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：[[1,0,0],[0,0,0],[0,0,0]]
 * 输出：4
 * 解释：
 * 海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] 不是 0 就是 1
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100001
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

void EnQueue(struct MyQueue *q, int x, int y, int dep)
{
    q->item[++q->rear][0] = x;
    q->item[q->rear][1] = y;
    q->item[q->rear][2] = dep;
    if (q->front == -1) {
        q->front = 0;
    }
}

void DeQueue(struct MyQueue *q, int *px, int *py, int *dep)
{
    *px = q->item[q->front][0];
    *py = q->item[q->front][1];
    *dep = q->item[q->front++][2];
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
}

int maxDistance(int** grid, int gridSize, int* gridColSize)
{
    int visited[101][101] = {0};

    struct MyQueue *q = CreateQueue();
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                visited[i][j] = 1;
                EnQueue(q, i, j, 0);
            }
        }
    }

    int x, y, depth = 0;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!IsEmpty(q)) {
        DeQueue(q, &x, &y, &depth);
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= gridSize || ny < 0 || ny >= gridColSize[0]) {
                continue;
            }

            if (visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                EnQueue(q, nx, ny, depth + 1);
            }
        }
    }

    free(q);
    if (depth == 0) {
        return -1;
    }
    return depth;
}



```
