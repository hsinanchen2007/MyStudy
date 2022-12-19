### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums.length == 0){
            return 0;
        }else if(target>nums[nums.length-1]){
            return nums.length;
        }
        for(int i = 0;i<nums.length;i++){
            if(target == nums[i]){
                return i;
            }else if(target>nums[i] && target < nums[i+1]){
                return i+1;
            }
        }
        return 0;
    }
}
```