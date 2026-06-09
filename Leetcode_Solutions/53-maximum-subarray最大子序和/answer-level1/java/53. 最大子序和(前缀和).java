前缀和　方法
```java []
class Solution {
    public int maxSubArray(int[] nums) {
        //前缀和
        if (nums == null || nums.length == 0){
            return 0;
        }
        
        int max = Integer.MIN_VALUE;
        for(int i = 0, sum = 0, minSum = 0; i < nums.length; i++){
            sum += nums[i];　　//累积求从0到当前i的总和sum
            max = Math.max(max, sum-minSum);　　//sum减去这个最小sum值就是这一段总的最大值
            minSum = Math.min(minSum, sum);  //　找出从0到当前索引i之间的　最小sum值
        }
        return max;
    }
}
```
```java []
class Solution {
    public int maxSubArray(int[] nums) {
        int ans = Integer.MIN_VALUE;
        int sum = 0;

        for(int i = 0; i < nums.length; ++i){
            //当某段和为负数时，就舍去。
            if(sum < 0){
                sum = 0;
            }
            sum += nums[i];

            if(ans < sum){
                ans = sum;
            }
        }
        return ans;
    }
}
```
时间复杂度On



