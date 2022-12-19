### 解题思路


### 代码

```java
class Solution {
    public int search(int[] nums, int target){
        if(nums == null || nums.length == 0)
            return 0;
            
        int count = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == target){
                count += 1;
            }
            if(nums[i] > target)
                break;
        }
        return count;
    }
}
```