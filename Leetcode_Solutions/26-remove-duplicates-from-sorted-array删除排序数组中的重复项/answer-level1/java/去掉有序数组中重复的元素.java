### 解题思路
- 输入：数组是一个对象，有可能为null
- 解法：重复的数字在数组中是相邻的，因此可以通过比较当前数据与最后一个不重复的数字进行对比，如果不相等可以将当前数字放在最后一个不重复数组的后面。题目的关键在于需要意识到这个数组至少需要被遍历一遍

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        assert nums != null;
        if(nums.length <= 1){
            return nums.length;
        }
        int index = 0;
        for(int i = 1 ; i < nums.length ; i++){
            if(nums[i] != nums[index]){
                nums[++index] = nums[i]; 
            }
        }
        return ++index;
    }
}
```