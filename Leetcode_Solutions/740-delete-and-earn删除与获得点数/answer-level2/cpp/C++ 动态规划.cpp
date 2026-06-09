### 解题思路
动态规划是一个一个动作进行，动作让一个状态转变成另一个状态。本题中，先做一个转换，先用value[i]统计数字i可以得到分数，再用dp[i]表示从1到i可以获得的最大得分。
例如：对于输入 [2,2,3,3,3,4]，数字2出现2次，得分为2×2=4,则value[2]=4, 同理，value[3]=9, value[4]=4；
得到value = [0, 0, 4, 9, 4]，下标从0开始
dp[i]为从1到i可以获得的最高分，dp[i] = max(dp[i-1], dp[i-2]+value[i])，新来一个数i，要么不理它，当前最高分仍然为dp[i-1]；要么理它，代价是不理i-1，当前最高分为dp[i-2]+value[i]。我们取让点数更高那个。

### 代码

```cpp
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
		int value[20001] = {0};
		int dp[20001] = {0};
		
		for(auto n:nums) { // 统计各个数字对应总点数
			value[n] += n;
		}
		
		dp[1] = value[1];
		for(int i=2; i<20001; i++) {
			dp[i] = max(dp[i-1], dp[i-2] + value[i]);//动态规划
		}
		
		return dp[20000];
    }
};
```