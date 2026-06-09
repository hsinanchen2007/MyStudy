### 解题思路
此处撰写解题思路
// DFS 回溯法：从太平洋和大西洋分别往中间进行搜索（下一个节点的满足条件是比该节点的值大），用2个数组分别记录每一个点是否可以流向大或者太，
// 最后对2个数组进行遍历，找到满足要求的点。

// 4个方向的处理，使用2维数组处理，值得学习。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define CAN_FLOW 1
#define NOT_FLOW 0

int m;
int n;

int AREA[4][2] = {{0, 1},
                  {1, 0},
                  {0, -1},
                  {-1, 0}};

bool isInArea(int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}

// 4个方向进行遍历
void DfsWater(int** matrix, int x, int y, int** flowArray)
{
    for (int i = 0; i < 4; i++) {
        int newX = x + AREA[i][0];
        int newY = y + AREA[i][1];

        if (isInArea(newX, newY) && flowArray[newX][newY] == NOT_FLOW
            && matrix[newX][newY] >= matrix[x][y]) {
            flowArray[newX][newY] = CAN_FLOW;
            DfsWater(matrix, newX, newY, flowArray);
        }
    }
}

int** pacificAtlantic(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL) {
        *returnSize = 0;
        returnColumnSizes = NULL;
        return NULL;
    }

    m = matrixSize;
    n = matrixColSize[0];
    int size = m * n;

    int **pacificFlow = (int **)malloc(size * sizeof(int*)); // 标记是否可流到太平洋
    if (pacificFlow != NULL) {
        memset(pacificFlow, 0 , size * sizeof(int*));
    }

    int **atlanticFlow = (int **)malloc(size * sizeof(int*)); // 标记是否可流到大西洋
    if (atlanticFlow != NULL) {
        memset(atlanticFlow, 0 , size * sizeof(int*));
    }

    // 初始化
    for (int i = 0; i < m; i++) {
        pacificFlow[i] = (int *)malloc(n * sizeof(int));
        memset(pacificFlow[i], 0 , n * sizeof(int));

        atlanticFlow[i] = (int *)malloc(n * sizeof(int));
        memset(atlanticFlow[i], 0 , n * sizeof(int));
    }

    *returnSize = 0;
    int** result = (int **)malloc(size * sizeof(int*)); // 记录结果，一维数组指针
    if (result != NULL) {
        memset(result, 0 , size * sizeof(int*));
    }
    *returnColumnSizes = (int *)malloc(size * sizeof(int));

    // DFS 回溯法：从太平洋和大西洋分别往中间进行搜索（下一个节点的满足条件是比该节点的值大），用2个数组分别记录每一个点是否可以流向大或者太，
    // 最后对2个数组进行遍历，找到满足要求的点。
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 || j == 0) && (pacificFlow[i][j] == NOT_FLOW)) {
                pacificFlow[i][j] = CAN_FLOW;
                DfsWater(matrix, i, j, pacificFlow);
            }

            if ((i == m - 1 || j == n - 1) && (atlanticFlow[i][j] == NOT_FLOW)) {
                atlanticFlow[i][j] = CAN_FLOW;
                DfsWater(matrix, i, j, atlanticFlow);
            }
        }
    }

    // 遍历2个2维数组，相同位置都为1的点即是满足要求的点
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((atlanticFlow[i][j] == CAN_FLOW) && (pacificFlow[i][j] == CAN_FLOW)) {
                result[count] = (int *)malloc(2 * sizeof(int));
                result[count][0] = i;
                result[count][1] = j;
                count++;
            }
        }
    }

    *returnSize = count;
    for (int i = 0; i < count; i++) {
        (*returnColumnSizes)[i] = 2; // 返回数组的二维数组result每行的元素数量
    }

    return result;
}
```