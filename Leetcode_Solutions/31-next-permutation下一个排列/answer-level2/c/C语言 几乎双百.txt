### 解题思路
此题目可以认为是找大于输入数值的下一个数
比如输入[1, 3, 2]，可以认为是132，那么如何找到由[1, 2, 3]组成的大于132的下一个数
这个数可以分为左右两个部分，右侧是递减数列，左侧是剩余的部分。
递减数列已经是可以表示的最大值，所以要调整的数应该是在边界处。
找到边界之后，在递减序列，从右向左找第一个大于边界值的数，然后和边界值互换
之后把递减数列排序成递增即可
![image.png](https://pic.leetcode-cn.com/d310cd2c8848edd25149a1011c31a2dcdc67f7eb0fb7a1cb9279ce1476faf9c0-image.png)

### 代码

```c
int cmp(const void *a, const void *b)
{
    return *(int*)a > *(int*)b;
}

void nextPermutation(int* nums, int numsSize){
    int i, j, tmp;
    if (numsSize <= 1) {
        return;
    }
    /* 从右向左找到递减序列的边界 */
    for (i = numsSize - 1; i > 0; i--) {
        if (nums[i] > nums[i-1]) {
            break;
        }
    }
    /* 整个数组递减 */
    if (i == 0) {
        qsort(nums, numsSize, sizeof(int), cmp);
        return;
    }
    /* 在递减序列里，从右向左找到第一个大于边界的数值，然后和边界进行互换 */
    tmp = nums[i - 1];
    for (j = numsSize - 1; j > (i - 1); j--) {
        if (nums[j] > tmp) {
            break;
        }
    }
    nums[i - 1] = nums[j];
    nums[j] = tmp;
    /* 将递减序列转换成递增序列 */
    qsort(&nums[i], numsSize - i, sizeof(int), cmp);
    return; 
}
```