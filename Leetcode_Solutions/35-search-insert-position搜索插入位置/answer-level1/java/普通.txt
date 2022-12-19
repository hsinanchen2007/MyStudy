### 解题思路
先处理特殊情况
1. 数组长度只有1
    * target小于等于nums[0] return 0;
    * target大于nums[0] return 1; 
2. target大于数组最后的数字 return nums.length
3. 常规情况
    * 遍历数组，若target小于等于下标位置数，返回下标
### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int length = nums.length;
        if(length == 1) {
            if (target > nums[0])
                return 1;
            else
                return 0;
        }
        if(target > nums[length-1])
            return length;
        for(int i = 0; i < length; i++){
            if(target <= nums[i]){
                return i;
            }
        }
        return 0;
    }
}
```