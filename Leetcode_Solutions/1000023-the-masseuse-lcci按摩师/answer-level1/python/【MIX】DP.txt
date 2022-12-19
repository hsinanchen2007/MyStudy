### 解题思路
House Robber的题型

### 代码

```java []
class Solution {
    public int massage(int[] nums) {
        // 空间复杂度优化
        int N = nums.length;
        // old记录[0..i-2]的最优方案, now记录[0..i-1]的最优方案
        int old = 0, now = 0;
        for(int i=0; i<N; ++i){
            int temp = Math.max(old + nums[i], now);
            old = now;
            now = temp;
        }

        return now;

    }
}
```
```python3 []
class Solution:
    def massage(self, nums: List[int]) -> int:
        # dp求解
        N = len(nums)
        if N == 0:
            return 0

        if N <= 2:
            return max(nums)


        dp = [0 for _ in range(N)]
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, N):
            dp[i] = max(dp[i-1], dp[i-2]+nums[i])
        
        return max(dp)
         
```
```c++ []
class Solution {
public:
    int massage(vector<int>& nums) {
        int N = nums.size();
        if(N == 0)
            return 0;
        if(N == 1)
            return nums[0];
        if(N == 2)
            return max(nums[0], nums[1]);

        int *dp = new int[N]();
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        int maxV = dp[0];
        for(int i=2; i<N; ++i){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
            maxV = max(maxV, dp[i]);
        }
        
        delete []dp;
        dp = nullptr;

        return maxV; 
    }
};
```