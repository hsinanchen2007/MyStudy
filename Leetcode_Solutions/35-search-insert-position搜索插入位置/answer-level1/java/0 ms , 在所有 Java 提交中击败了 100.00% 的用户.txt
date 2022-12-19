### 解题思路


### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        
        for(int i=0;i<nums.length;i++){
            if(nums[i]==target){
                return i;
            }
        }
        for(int j=0;j<nums.length;j++){
            if(target < nums[j]){
                return j;
            }
            if(target>nums[nums.length-1]){
                return nums.length;
            }
        }
        return 0;
    }
}
```