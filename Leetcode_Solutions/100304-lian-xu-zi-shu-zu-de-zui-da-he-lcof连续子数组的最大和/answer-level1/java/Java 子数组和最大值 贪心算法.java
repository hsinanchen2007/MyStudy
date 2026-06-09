### 解题思路
    max记录全局最大值，sum记录区间和，如果当前sum>0，那么可以继续和后面的数求和，否则就从0开始

### 代码

```java
//贪心算法
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums==null || nums.length==0){
            return 0;
        }
        int max=Integer.MIN_VALUE,sum=0;
        //如果数组和为负数，那么和sum就从0开始
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            max=Math.max(max,sum);
            sum=Math.max(sum,0);
        }
        return max;
    }
}
```