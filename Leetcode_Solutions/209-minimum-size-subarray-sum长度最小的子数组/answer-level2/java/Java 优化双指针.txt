### 解题思路
普通双指针解法中，是通过固定左指针，并不断扩大右方区域来进行求解，这样时间效率较低。
我们可以这样优化：
- 构建一个动态区间，保持该区间里所有数的和sum>=s。
- 若在当前位置时sum>=s，则将左指针右移，缩小区间，并更新最短长度。


### 代码

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int sum=0;
        int left=0;
        int ans=Integer.MAX_VALUE;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            while(sum>=s){
                ans=Math.min(ans,i-left+1);
                sum-=nums[left++];
            }
        }
        return ans==Integer.MAX_VALUE?0:ans;
    }
}
```