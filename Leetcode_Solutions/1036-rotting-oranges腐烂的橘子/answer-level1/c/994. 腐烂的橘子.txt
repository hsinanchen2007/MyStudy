### 解题思路
![image.png](https://pic.leetcode-cn.com/e6a49c2414ab1968aea34cb651fbc3633346e040fbe4bc59c7ffbaaa03a20abb-image.png)
广度优先搜索 + 堆栈
1、先遍历一遍数据，统计所有橘子，并找出所有的坏橘子；
2、以所有坏橘子为起点，使用广度优先搜索，计算每个橘子腐烂的最短时间，并标记所有腐烂橘子；
3、遍历时间表格，找出所有坏橘子，以及需要最短的时间（也就是表格里的最大值）；
4、如果腐烂橘子为橘子总数，就返回最短时间，否则返回 -1 （无法全部腐烂）；
### 代码

```c

#define DEBUG 0

typedef struct _node_t {
    struct _node_t *next;
    int x;
    int y;
} node_t;
void Push(node_t *head, int x, int y)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->x = x;
    new_node->y = y;
    new_node->next = head->next;
    head->next = new_node;
}
bool IsEmpty(node_t *head)
{
    return head->next == NULL;
}
node_t *Pop(node_t *head)
{
    node_t *node = NULL;
    if (!IsEmpty(head)) {
        node = head->next;
        head->next = node->next;
        node->next == NULL;
        return node;
    } else {
        return NULL;
    }
}
void MakeEmpty(node_t *head)
{
    node_t *p_node = NULL;
    while (!IsEmpty(head)) {
        p_node = Pop(head);
        free(p_node);
    }
}
#define DIRECTION_SIZE 4
#define X 0
#define Y 1
const int g_direction [DIRECTION_SIZE][2] = {
    {-1, 0},
    { 0,-1},
    { 0, 1},
    { 1, 0},
};
int GetDir(int dirIndex)
{
    return DIRECTION_SIZE - dirIndex - 1;
}

int Search(int** grid, int gridSize, int* gridColSize, int **time, int x, int y, int value, int dir_index)
{
    if ((x < 0 || x >= gridSize) || (y < 0 || y >= gridColSize[x])) {
        return -1;
    }
    if (grid[x][y] == 0) {
        return -1;
    }

    if (grid[x][y] == 1) {
        time[x][y] = value +1;
        grid[x][y] = 2;
    } else if (grid[x][y] == 2){
        if (time[x][y] > value + 1 || value < 0) {
                time[x][y] = value + 1;
        } else {
            return -1;
        }
    }

    if (DEBUG) {
        printf("<%d> x = %d, y = %d, value = %d, index = %d, grid[%d][%d] = %d, time[%d][%d] = %d\n",
        __LINE__, x, y, value, dir_index, x, y, grid[x][y], x, y, time[x][y]);
    }

    for (int i = 0; i < DIRECTION_SIZE; i++) {
        if (i == GetDir(dir_index)) {
            continue;
        }
        Search(grid, gridSize, gridColSize, time, x + g_direction[i][X], y + g_direction[i][Y], time[x][y], i);
    }

    return 0;
}
void PrintTime (int **grid, int **time, int gridSize, int* gridColSize)
{
    if(DEBUG == 0) return;
    for (int i =0; i <gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            printf("%3d", grid[i][j]);
        }
        printf("\n");
    }
    printf("---\n");

    for (int i =0; i <gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if ( time[i][j] < 0) {
                printf("  -");
            } else {
                printf("%3d", time[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n===\n");
    
}

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridColSize == NULL || gridSize < 1) return -1;

    int totalNum = 0;
    int badNum = 0;

    node_t *head = (node_t *)malloc(sizeof(node_t));
    head->next = NULL;
    int **time = (int **)malloc(sizeof(int *) * gridSize);

    // 统计坏橘子个数，并统计总橘子个数，用于判断橘子最终是否都损坏
    for (int i=0; i < gridSize; i++) {
        time[i] = (int *)malloc(sizeof(int) * gridColSize[i]);
        for (int j=0; j < gridColSize[i]; j++) {
            time[i][j] = -1;
            if (grid[i][j] == 2) {
                totalNum++;
                badNum++;
                Push(head, i, j);
                time[i][j] = 0;
            } else if (grid[i][j] == 1) {
                totalNum++;
            }
        }
        // 建立时间表，用来记录每个橘子损坏的时间
    }

    PrintTime(grid, time, gridSize, gridColSize);

    node_t *p_node = NULL;
    while (!IsEmpty(head)) {
        p_node = Pop(head);
        Search(grid, gridSize, gridColSize, time, p_node->x, p_node->y, -1, DIRECTION_SIZE);
        PrintTime(grid, time, gridSize, gridColSize);
        free(p_node);
    }
    free(head);

    int ret =0;
    badNum = 0;
    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridColSize[i]; j++) {
            if (grid[i][j] == 2) {
                badNum++;
            }
            if (time[i][j] > ret) {
                ret = time[i][j];
            }
        }
    }
    free(time);

    if (badNum < totalNum) {
        return -1;
    } else {
        return ret;
    }
}

/* test case
[[2,1,1],[1,1,0],[0,1,1]]

[[2,1,1],[0,1,1],[1,0,1]]

[[0,2]]

[[0]]

[[1]]

[[2]]

[[2,1,1],[1,1],[1,1,1]]

*/
```