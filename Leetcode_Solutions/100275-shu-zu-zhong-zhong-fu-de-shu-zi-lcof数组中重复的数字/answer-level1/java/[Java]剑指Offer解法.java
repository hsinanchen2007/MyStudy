### 解题思路
1. 首先比较m=nums[i]与下标i是否相等
2. 若不相等，则判断nums[i]与nums[m]是否相等，相等则可以返回，说明已找到结果；
3. 若nums[i]与nums[m]不相等，则将其交换，并继续上述判断，直到nums[i]与下标i相等，此时跳出while循环
时间复杂度O(n)，空间复杂度O(1)

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        if(nums==null || nums.length==0){
            return -1;
        }
        for(int i=0;i<nums.length;i++){
            if(nums[i]<0 || nums[i]>=nums.length){
                return -1;
            }
            while(i!=nums[i]){
                if(nums[i]==nums[nums[i]]){
                    return nums[i];
                }
                else{
                    int temp = nums[nums[i]];
                    nums[nums[i]] = nums[i];
                    nums[i] = temp;
                }
            }
        }
        return -1;
    }
}
```