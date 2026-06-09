思路：
(1) 在行方向上，利用滑动窗口固定宽度，然后在列方向找到最大连续的高度，二者乘积为当前窗口下最大面积。
(2) 窗口大小从列的大小开始，减到1，所有窗口下最大面积作为矩形中最大面积，即返回值。

代码：
#define MAX(a, b)       ((a) > (b) ? (a) : (b))

bool IsAllOne(char *row, int left, int right)
{
    if (left > right) {
        return false;
    }

    while (left <= right) {
        if (row[left] != '1' || row[right] != '1') {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int GetMaxArea(char **matrix, int matrixSize, int left, int right)
{
    int max = 0;
    int i, j;

    i = 0;
    while (i < matrixSize) {
        if (!IsAllOne(*(matrix + i), left, right)) {
            i++;
            continue;
        }
        j = i;
        while (j < matrixSize) {
            if (!IsAllOne(*(matrix + j), left, right)) {
                break;
            }
            j++;
        }
        max = MAX(max, j - i);
        i = j + 1;
    }

    return (right - left + 1) * max;
}

bool CheckColumnAllZero(char **matrix, int matrixSize, int column)
{
    int i;

    for (i = 0; i < matrixSize; i++) {
        if (*(*(matrix + i) + column) == '1') {
            return false;
        }
    }
    
    return true;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    int window;
    int column;
    int area = 0;
    int maxArea = 0;
    int i;

    if (matrix == NULL || matrixSize <= 0) {
        return 0;
    }

    window = matrixColSize[0];

    while (window >= 1) {
        for (column = 0; column <= matrixColSize[0] - window; column++) {
            if (CheckColumnAllZero(matrix, matrixSize, column) ||
                CheckColumnAllZero(matrix, matrixSize, column + window - 1)) {
                continue;
            }
            area = GetMaxArea(matrix, matrixSize, column, column + window - 1);
            maxArea = MAX(maxArea, area);
        }
        window--;
    }

    return maxArea;
}