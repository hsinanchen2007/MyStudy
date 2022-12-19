### 解题思路
![屏幕快照 2020-02-14 下午10.11.48.png](https://pic.leetcode-cn.com/5fb2f534d46fbee36aee1dcc28db15dc3f28e7db24b1f6a4b19ae696cfaacd53-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-14%20%E4%B8%8B%E5%8D%8810.11.48.png)
本题与[数组去重问题](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)解题思路一样，采用双指针，一个指向当前不等于val数组的后一位，另一个去遍历整个数组，当有不等于val的值时，赋值给index=current，并向后移一位。

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    if (numsSize <= 0) return numsSize;
    int current = 0;
    for (int slide = 0; slide < numsSize; slide++) {
        if (nums[slide] != val) {
            nums[current++] = nums[slide];
        }
    }
    return current;
}
```