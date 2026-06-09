### 解题思路

重点：**只要找一个**（之前面试今日头条的时候，以为要找全部的，痛呀）    

基本思路

1. 将数组一分为二（把山坡一分为二）
1. 分开的位置，必然有一方通向峰顶（要么左边通行峰顶，要么右边通向峰顶）
1. 循环一直到不能分

### 代码

```java
class Solution {
    public int findPeakElement(int[] nums) {
        return find(0, nums.length - 1, nums);
    }

    private int find(int left, int right, int[] nums) {
        if(left == right) {
            return left;
        }
        int mid = (left + right) / 2;
        return nums[mid] > nums[mid + 1]? 
            find(left, mid, nums): find(mid + 1, right, nums);
    }
}
```