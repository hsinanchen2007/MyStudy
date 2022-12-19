### 解题思路
维护一个指针 index，其取值范围为 0 ~ nums.length - 1，用于指明**数组左右部分当前的分界线**。
left 表示 index 左边所有数字的和，right 表示 index 右边所有数字的和。
当 left = right 时，返回对应的索引 index，否则 index 向右移动一位（index++）。
left值增加一个nums[index - 1]，right值减少一个nums[index]，直到满足 left = right 或 index = nums.length - 1 为止。

### 代码

```java
class Solution {
    public int pivotIndex(int[] nums) {
        if(nums.length == 0) return -1;
        int left = 0,right = 0;
        for(int i = 1;i < nums.length;i++) right += nums[i];
        if(right == 0) return 0;
        int index = 1;
        while(index < nums.length) {
            left += nums[index - 1];
            right -= nums[index];
            if(left == right) return index;
            index++;
        }
        return -1;
    }
}
```