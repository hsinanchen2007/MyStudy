### 解题思路
遍历数组，找到第一个不是递增的元素即可。
### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        if(nums==null||nums.length<=0){
            return Integer.MIN_VALUE;
        }
        for(int i=1;i<nums.length;i++){
            if(nums[i]<nums[i-1]){
                return nums[i];
            }
        }
        return nums[0];
    }
}
```