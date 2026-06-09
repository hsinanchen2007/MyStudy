### 解题思路
1. 一次遍历可以找出最大和第二大数， 貌似第三大也行。

在一个给定的数组nums中，总是存在一个最大元素 。

查找数组中的最大元素是否至少是数组中每个其他数字的两倍。

如果是，则返回最大元素的索引，否则返回-1。

示例 1:

输入: nums = [3, 6, 1, 0]
输出: 1
解释: 6是最大的整数, 对于数组中的其他整数,
6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.

### 代码

```c
int dominantIndex(int* nums, int numsSize){
    int i, max, second = 0, index = 0;

    max = nums[0];

    for (i = 1; i < numsSize; i++) {
        if (max < nums[i]) {
            second = max > second ? max : second;
            max = nums[i];
            index = i;
        } else if (nums[i] > second){
            second = nums[i];
        }
    }
    if (max >= second * 2)
        return index;
    else
        return -1;
}
```