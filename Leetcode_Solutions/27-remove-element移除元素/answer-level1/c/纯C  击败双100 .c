### 解题思路
    首先，明确这题就是删除数组中元素的操作，遍历数组，当遇到目标值val时，直接删除就好；
    其次，删除值也就是后面的数依次覆盖目标值val以及后面的的数，这时考虑是正向删除还是反向删除，很明显反向删除内存消耗更小；
    最终代码如下，开始用了memcpy函数，但是有指针越界的情况，没找到原因，最后用的for循环覆盖。

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int i, j, count = 0, result = 0;
//    if (nums[numsSize - 1] == val) {
//        count ++;
//    }
    for (i = numsSize - 1; i >= 0; --i) {
        if (nums[i] == val){
            for (j = 0; j < result; ++j) {
                nums[i + j] = nums[i + 1 +j];
            }
//            memcpy(&nums[i], &nums[i + 1], result * sizeof(int));
            count ++;
        }
        result ++;
    }
    return result - count;
}
```