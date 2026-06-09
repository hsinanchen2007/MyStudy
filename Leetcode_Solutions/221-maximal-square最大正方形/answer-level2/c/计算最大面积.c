### 解题思路
1、按照动态规划的思路，每个值都获取 最小的(左，左上，上) + 1
![image.png](https://pic.leetcode-cn.com/c70419d3c0236a2710270ae1af7e85171a4fce1c77e853d586cfb518980bd04c-image.png)
2、获取值的时候，从下面几个场景处理：
（1）当前值为0，不处理
（2）左、左上、上 三个值为0，不处理
（3）计算长度，按照：最小的(左，左上，上) + 1
3、针对只有1的场景，进行特殊处理（遍历0行和0列）

### 代码

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int getMinVal(int a, int b, int c)
{
    int minVal;

    minVal = MIN(a, b);
    minVal = MIN(minVal, c);
    return minVal;
}

int maximalSquare(char **matrix, int matrixSize, int *matrixColSize)
{
    int area;

    if (matrixSize <= 0) {
        return 0;
    }

    if (matrixColSize[0] == 0) {
        return 0;
    }

    area = 0;
    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixColSize[row]; col++) {
            if (row == 0 || col == 0) {
                if (matrix[row][col] == '1') {
                    area = MAX(area, 1);
                }
                continue;
            }

            if (matrix[row][col] == '0') {
                continue;
            }

            area = MAX(area, 1);
            if (matrix[row - 1][col - 1] == '0') {
                continue;
            }

            if (matrix[row - 1][col] == '0') {
                continue;
            }

            if (matrix[row][col - 1] == '0') {
                continue;
            }


            matrix[row][col] = getMinVal(matrix[row - 1][col], matrix[row][col - 1], matrix[row - 1][col - 1]) + 1;
            area = MAX(area, matrix[row][col] - '0');
        }
    }
    return area * area;
}
```