### 解题思路
    整体思路：找到左上、右下，判中间，算面积。
    具体实现：
    遍历所有点，作为左上。  
        向右向下找最长边。
            限定一个宽度，从左往右找，找到最后一个满足的竖边。则得到一个长方形。计算面积。
            宽度加一，相同方法，再找到一个，计算面积。保留最大的。
            如果按可能的最大宽度和最大长度算出来的最大面积都比已知最大面积小，就不用继续了。
### 代码

```c
/*
    找矩形：找到左上、右下，判中间，算面积。
    遍历所有点，作为左上。  
        向右向下找最长边。
            限定一个宽度，从左往右找，找到最后一个满足的竖边。则得到一个长方形。计算面积。
            宽度减一，相同方法，再找到一个，计算面积。保留最大的。
            如果按当前的宽度和长度算出来的最大面积都比已知最大面积小，就不用继续了。

*/

typedef struct tagPOS_S{
    int X;
    int Y;
}POS_S;

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL || *matrixColSize == 0) {
        return 0;
    }

    int Y, X, x, y;
    POS_S leftUp = {0};
    POS_S rightUp = {0};
    POS_S leftDn = {0};
    POS_S rightDn = {0};
    int curAreaSize = 0;
    int MaxAreaSize = 0;
    int posibelMax = 0;
    for (Y = 0; Y < matrixSize; Y++) {
        leftUp.Y = Y;
        for (X = 0; X < matrixColSize[Y]; X++) {
            /* 指定左上角的点 */
            if (matrix[Y][X] == '0') {
                continue;
            }
            leftUp.X = X;

            /* 省时判断：如果剩余面积小于最大值，则不必继续遍历 */
            posibelMax = (matrixColSize[Y] - leftUp.X) * (matrixSize - leftUp.Y);
            if (MaxAreaSize > posibelMax) {
                break;
            }           

            /* 向右找最长边。 */
            for (x = X; x < matrixColSize[Y]; x++) {
                if (matrix[Y][x] == '0') {
                    break;
                }
            }
            rightUp.X = x - 1;
            rightUp.Y = Y;

            /* 向下找最长边。 */
            for (y = Y; y < matrixSize; y++) {
                if (matrix[y][X] == '0') {
                    break;
                }
            }
            leftDn.X = X;
            leftDn.Y = y - 1;

            /* 遍历最大长和宽范围内所有长方形的面积。 省时判断：可能的最大面积比已知最大面积小，则略过*/
            posibelMax = (rightUp.X - leftUp.X + 1) * (leftDn.Y - leftUp.Y + 1);
            if (MaxAreaSize > posibelMax) {
                continue;
            }

            int w, l;
            for (w = leftUp.Y; w <= leftDn.Y; w++) 
            {
                for (l = leftUp.X; l <= rightUp.X; l++) {
                    if (matrix[w][l] == '0') {
                        rightUp.X = l - 1;
                        break;
                    }
                }

                curAreaSize = (rightUp.X - leftUp.X + 1) * (w - leftUp.Y + 1);
                MaxAreaSize = MaxAreaSize > curAreaSize ? MaxAreaSize : curAreaSize;
            }
        }
    }

    return MaxAreaSize;
}
```