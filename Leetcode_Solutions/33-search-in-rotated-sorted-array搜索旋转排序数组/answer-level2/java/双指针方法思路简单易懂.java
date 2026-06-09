### 解题思路
1. 数组被翻转后的，那么也是两段有序的，且数组头大于数组尾
2. 一个数组头指针，一个数组尾指针。数组头指针++，尾指针--
3. 两个指针同时对比target

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if (nums.length == 0) return -1;
        for (int i=0, j=nums.length - 1; i <= j; i++, j--) {
            if (nums[i] <= target) {
                if (nums[i] == target) return i;
            }
            if (nums[j] >= target) {
                if (nums[j] == target) return j;
            }
        }
        return -1;
    }
}
```