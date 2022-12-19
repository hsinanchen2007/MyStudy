### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(target<nums[0]){
            return 0;
        }
        if(target>nums[nums.length-1]){
            return nums.length;
        }
        for(int i=0;i<nums.length;i++){
            if(target==nums[i]){
                return i;
            }
        }
        for(int i=0;i<nums.length;i++){
            if(nums[i]>target){
                return i;
            }
        }
        return -1; 
    }
}
```