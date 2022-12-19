### 解题思路
经典的二分查找题型，使用典型的二分查找模板，这里给出C语言解法。
1.初始化left，right，top，bottem

1.首先二分查找left列（以行开始也可以），找到并更新bottem，使得凡是行号大于bottem，值都大于target；

2.然后对bottem为行进行二分查找，找到并更新left，使得凡是列号小于left，值都小于target；

3.重复1，2步骤直至找到结果

注意判断是否找到的条件。

### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//【算法思路】二分法。二维有序矩阵定位一个元素，算法复杂度可以降低至logn
// 根据行列规律利用二分发逼近结果
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if(matrixRowSize == 0 || matrixColSize == 0) {
        return false;
    }
    int row = matrixRowSize;
    int col = matrixColSize;

    int top = 0, bot = row - 1;
    int left = 0, right = col - 1;

    while(1) {
        //先找列
        int tt = top, bb = bot;

        if(target < matrix[tt][left]) {
            return false;
        } else if(target > matrix[bb][left]) {
            tt = bb + 1;
        } else if(target == matrix[tt][left] || target == matrix[bb][left]) {
            return true;
        }

        //printf("left = %d, right = %d\n", left, right);
        while(tt < bb) {
            //printf("tt = %d, bb = %d\n", tt, bb);
            int mid = (tt + bb) / 2;

            if(matrix[mid][left] > target) {
                bb = mid;
            } else {
                tt = mid + 1;
            }
        }

        if(matrix[tt - 1][left] == target) {
            return true;
        } else {
            //调整数据区间，tt及以上行都大于target
            bot = tt - 1;
        }

        int ll = left, rr = right;

        if(target > matrix[bot][rr]) {
            return false;
        } else if(target == matrix[bot][ll] || target == matrix[bot][rr] ) {
            return true;
        }

        //printf("top = %d, bottom = %d\n", top, bot);
        while(ll < rr) {
            //printf("ll = %d, rr = %d\n", ll, rr);
            int mid = (ll + rr) / 2;

            if(matrix[bot][mid] > target) {
                rr = mid;
            } else {
                ll = mid + 1;
            }
        }

        if(matrix[bot][ll - 1] == target) {
            return true;
        } else {
            //调整数据区间，tt及以上行都大于target
            left = ll;
        }
    }
}
```