### 解题思路
![image.png](https://pic.leetcode-cn.com/7ecdc60f7762cbd88810e9e4fb042410bda39a65aa7053c609901b8bbbcd1c36-image.png)
Next Greater Number(前后遮挡求最值/面积等参数)问题都可以用单调栈解答，这类问题的重点是**从后往前**看
1、纯递增数列如456，从后往前看时面积就是高度乘到最后的距离
6的面积是6
5的面积是5 * 2
4的面积是4 * 3

2、若出现非递增项，面积可以包含进来，比如4562，上述面积可以表示为
6的面积是6 + 2
5的面积是5 * 2 + 2
4的面积是4 * 3 + 2

故只需判断数列的递增性：若递增则参数入栈，若出现非递增项，则计算栈中当前的最大面积，并将栈的部分参数出栈保证递增

### 代码

```c
int g_stack[50000] = {0};
int g_stackLen;

int largestRectangleArea(int* heights, int heightsSize)
{
    int maxArea = 0;
    int tmpArea;
    int h;
    int l;
    int loop;

    // 初始化
    g_stack[0] = -1;
    g_stackLen = 1;

    for (loop = 0; loop < heightsSize; loop++) {
        /* 1. 每找到一个非递增的高度则计算面积并出栈 */
        while ((g_stack[g_stackLen - 1] >= 0) && (heights[loop] < heights[g_stack[g_stackLen - 1]])) {
            l = loop - 1 - g_stack[g_stackLen - 2];     // 由于为单调递增, 故长度为该点到当前非递增点
            h = heights[g_stack[g_stackLen - 1]];       // 高度即为该点高度
            tmpArea = l * h;
            maxArea = (maxArea > tmpArea) ? maxArea : tmpArea;
            g_stackLen--;
        }
        /* 2. 新参数入栈 */
        g_stack[g_stackLen++] = loop;
    }

    // 3. 结束时可认为单调递减, 再执行一次运算
    while (g_stack[g_stackLen - 1] >= 0) {
        l = loop - 1 - g_stack[g_stackLen - 2];     // 由于为单调递增, 故长度为该点到当前非递增点
        h = heights[g_stack[g_stackLen - 1]];       // 高度即为该点高度
        tmpArea = l * h;
        maxArea = (maxArea > tmpArea) ? maxArea : tmpArea;
        g_stackLen--;
    }

    return maxArea;
}
```