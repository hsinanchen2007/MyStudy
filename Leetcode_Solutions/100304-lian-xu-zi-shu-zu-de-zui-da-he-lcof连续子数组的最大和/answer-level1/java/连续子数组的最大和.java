### 解题思路
连续子树组的最大和，累加过以后还要和当前下标对应的数字比较大小；
max就是用来存储之前数组中的连续最大和
### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int max = nums[0];
        int res= nums[0];
        for(int i=1;i<nums.length;i++){
            res = Math.max(res+nums[i],nums[i]);
            max = Math.max(res,max);
        }
        return max;
    }
}
```