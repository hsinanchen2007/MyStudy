简单的if语句实现

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int i,j=0;
        for(i= 0;i<nums.length;i++){
            if(target > nums[i]){
                if(i == nums.length-1){
                    return (j=nums.length);
                }else continue;
            }
            else if(target == nums[i]){
                return (j=i);
            }
            else if(target < nums[i]){
                return (j=i);
            }
        }
        return j;
    }
}
```