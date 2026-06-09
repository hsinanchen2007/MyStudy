### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums == null){
            return 0;
        }
        int Max = nums[0];
        int lastMax = nums[0];
        for(int i = 1; i < nums.length; i++){
            if(lastMax > 0){
                lastMax = lastMax + nums[i]; // 上一次的最大值带来正收益，加上最为本次的最大值（下一次的上一次最大值）。
            }
            else{
                lastMax = nums[i]; // 上一次的最大值带来负收益，丢弃，本次结果作为下一次的上一次最大值。
            }
            Max = Math.max(Max, lastMax);  // 全局最大值取本次的最大值和上一次的最大值中的最大值。
        }
        return Max;
    }
}
```