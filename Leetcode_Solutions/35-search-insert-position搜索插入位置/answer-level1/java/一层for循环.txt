### 解题思路
因为给的数组是升序的，所以从头依次遍历就好了，遇到大于或等于目标值的数字就是应该被替换的数字，返回这个数字的索引即可。如果遍历完数组都没找到，那就应该放到数组最后。

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums==null||nums.length==0){
            return -1;
        }
        for(int i=0;i<nums.length;i++){
            //应该被替换的数字
            if(nums[i]>=target){
                return i;
            }
        }
        //数组中的数字都比目标数字小
        return nums.length;
    }
}
```