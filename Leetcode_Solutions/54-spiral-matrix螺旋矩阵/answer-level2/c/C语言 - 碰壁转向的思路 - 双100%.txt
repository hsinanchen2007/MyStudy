结果：
![Snipaste_2020-03-20_21-36-30.png](https://pic.leetcode-cn.com/c3717ebacc04f6e4b1ab9e30c3e14c31f1766ee3a898becbaf3b60f41056f450-Snipaste_2020-03-20_21-36-30.png)


### 解题思路

- 思路：制造一堵墙，每走完一圈，墙就厚一分。
    1. 需要注意的是，这堵墙最好是在第三面走完就加，因为第四面很明显，最后一位已经被截断，到倒数第二层就要转向，再来一轮外循环
    2. 外循环是有判断条件的哦，不是什么while(true)，那样的话四层内循环都要判断，太麻烦了
    3. 当然，外循环带条件，代价就是走完两面就要判断是否元素到头了，到头就要直接break，不然相当于会多走半轮循环，导致溢出
    4. 最后我还用了一个取巧的方法，就是全用**`++i` `++j` `++i` `--j`**，可以简化代码，别忘了j的初始值是-1就好，以及内循环的判断条件也会有一点点调整


- 这道题和之前同样是矩阵换序输出的 “[498.对角线遍历](https://leetcode-cn.com/problems/diagonal-traverse/)” 异曲同工。
    那道题我也用了类似的方法，[戳这里可以查看我的题解](https://leetcode-cn.com/problems/diagonal-traverse/solution/cyu-yan-yi-lun-die-dai-fu-zhi-dai-ma-qing-shuang-s/)~

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0) {
        *returnSize = 0; return 0;
    }
    *returnSize = matrixSize * (*matrixColSize);
    int* ans = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0, j = -1, num = 0, level = 0;
    while (num < *returnSize) {
        while (j < (*matrixColSize) - 1 - level) ans[num++] = matrix[i][++j];
        while (i < matrixSize - 1 - level) ans[num++] = matrix[++i][j];
        if (num == *returnSize) break;
        while (j > level) ans[num++] = matrix[i][--j];
        level++;
        while (i > level) ans[num++] = matrix[--i][j];
    }
    return ans;
}
```