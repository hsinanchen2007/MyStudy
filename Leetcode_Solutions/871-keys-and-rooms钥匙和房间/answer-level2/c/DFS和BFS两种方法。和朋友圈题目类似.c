思路：本题和朋友圈（leetcode 547题）类似，相比本题需要先构建无向图，遍历一遍没有结束可以提前返回
方法一：DFS
#include <time.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <securec.h>

#define DEBUG 0  // 调试开关：1打开，0关闭

#define NUM_MAX 1000

int book[NUM_MAX];  // 标记是否访问过

// cur是当前所在的顶点编号
void dfs(int cur, int **M, int MSize, int *MColSize)
{
    int i;

    // 从0号顶点到Msize-1号顶点依次尝试，看哪些顶点与当前顶点有边相连
    for (i = 0; i < MSize; i++) {
        // 如果有边相连，且没有走过
        if (book[i] == 0 && M[cur][i] == 1) {
            book[i] = 1;
            // 从顶点i出发再继续遍历
            dfs(i, M, MSize, MColSize);
        }
    }

    return;  // 所有可能都完事的时候返回
}

int findCircleNum(int **M, int MSize, int *MColSize)
{
    int i, j;
    int num = 0;  // 朋友圈个数计数变量
    clock_t start, end;

#if DEBUG
    printf("MSize = %d, MColSize[0] = %d\n", MSize, MColSize[0]);
    // 打印矩阵
    for (i = 0; i < MSize; i++) {
        for (j = 0; j < MColSize[i]; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    start = clock();
#endif

    memset(book, 0, sizeof(int) * NUM_MAX);
    // 对每一个大于0的点尝试进行dfs
    for (i = 0; i < MSize; i++) {
        for (j = 0; j < MColSize[i]; j++) {
            if (book[i] == 0 && M[i][j] > 0) {
                if (num == 1) {
                    return INT_MAX;
                }
                book[i] = 1;
                dfs(i, M, MSize, MColSize);
                num++;
            }
        }
    }

#if DEBUG
    // 结果输出
    // 打印朋友圈个数
    printf("%d", num);

    end = clock();
    printf("\ntime:%ld ms\n", (end - start));

    if ((end - start) > 1000) {
        printf("Timeout!\n");
    }
#endif

    return num;
}

bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize)
{
    int i, j;
    int MSize;
    int *MColSize;
    int result;

    int **p = (int **)malloc(roomsSize * sizeof(int *));
    if (p == NULL) {
        return 0;
    }
    for (i = 0; i < roomsSize; i++) {
        p[i] = (int *)malloc(roomsSize * sizeof(int));
        if (p[i] == NULL) {
            return 0;
        }
    }
    for (i = 0; i < roomsSize; i++) {
        memset(p[i], 0, roomsSize * sizeof(int));
    }
    
    MSize = roomsSize;
    MColSize = (int *)malloc(MSize * sizeof(int));
    if (MColSize == NULL) {
        return 0;
    }
    for (i = 0; i < MSize; i++) {
        MColSize[i] = MSize;
    }
    
    for (i = 0; i < roomsSize; i++) {
        for (j = 0; j < roomsColSize[i]; j++) {
            p[i][rooms[i][j]] = 1;
        }
    }
    for (i = 0; i < MSize; i++) {
        p[i][i] = 1;
    }
    
    result = findCircleNum(p, MSize, MColSize);
    
    if (result == 1) {
        return true;
    } else {
        return false;
    }
}
方法二：BFS
#include <time.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0  // 调试开关：1打开，0关闭
#define NUM_MAX 1000

int book[NUM_MAX];  // 标记是否访问过

// cur是当前所在的顶点编号
void bfs(int cur, int **M, int MSize, int *MColSize)
{
    int i;
    int que[NUM_MAX * NUM_MAX];
    // 队列初始化
    int head = 0, tail = 0;

    memset(que, 0, sizeof(int) * (NUM_MAX));
    // 从cur号顶点出发，将cur号顶点加入队列
    que[tail] = cur;
    tail++;
    book[0] = cur;

    // 当队列不为空的时候循环
    while (head < tail) {
        // 获取当前正在访问的顶点编号
        cur = que[head];
        // 从0号顶点到Msize-1号顶点依次尝试，看哪些顶点与当前顶点有边相连
        for (i = 0; i < MSize; i++) {
            // 如果有边相连，且没有走过
            if (book[i] == 0 && M[cur][i] == 1) {
                que[tail] = i;
                tail++;
                book[i] = 1;
            }
        }
        head++;
    }
}

int findCircleNum(int **M, int MSize, int *MColSize)
{
    int i, j;
    int num = 0;  // 朋友圈个数计数变量
    clock_t start, end;

#if DEBUG
    printf("MSize = %d, MColSize[0] = %d\n", MSize, MColSize[0]);
    // 打印矩阵
    for (i = 0; i < MSize; i++) {
        for (j = 0; j < MColSize[i]; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    start = clock();
#endif

    memset(book, 0, sizeof(int) * NUM_MAX);
    // 对每一个大于0的点尝试进行dfs
    for (i = 0; i < MSize; i++) {
        for (j = 0; j < MColSize[i]; j++) {
            if (book[i] == 0 && M[i][j] > 0) {
                if (num == 1) {
                    return INT_MAX;
                }
                bfs(i, M, MSize, MColSize);
                num++;
            }
        }
    }

#if DEBUG
    // 结果输出
    // 打印朋友圈个数
    printf("%d", num);

    end = clock();
    printf("\ntime:%ld ms\n", (end - start));

    if ((end - start) > 1000) {
        printf("Timeout!\n");
    }
#endif

    return num;
}

bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize)
{
    int i, j;
    int MSize;
    int *MColSize;
    int result;

    int **p = (int **)malloc(roomsSize * sizeof(int *));
    if (p == NULL) {
        return 0;
    }
    for (i = 0; i < roomsSize; i++) {
        p[i] = (int *)malloc(roomsSize * sizeof(int));
        if (p[i] == NULL) {
            return 0;
        }
    }
    for (i = 0; i < roomsSize; i++) {
        memset(p[i], 0, roomsSize * sizeof(int));
    }
    
    MSize = roomsSize;
    MColSize = (int *)malloc(MSize * sizeof(int));
    if (MColSize == NULL) {
        return 0;
    }
    for (i = 0; i < MSize; i++) {
        MColSize[i] = MSize;
    }
    
    for (i = 0; i < roomsSize; i++) {
        for (j = 0; j < roomsColSize[i]; j++) {
            p[i][rooms[i][j]] = 1;
        }
    }
    for (i = 0; i < MSize; i++) {
        p[i][i] = 1;
    }
    
    result = findCircleNum(p, MSize, MColSize);
    
    if (result == 1) {
        return true;
    } else {
        return false;
    }
}