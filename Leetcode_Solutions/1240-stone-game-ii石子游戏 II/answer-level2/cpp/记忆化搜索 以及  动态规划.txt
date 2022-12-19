记忆化搜索的过程，更像是我们拿到题目首先预想的那样，在这个基础上可以更好地理解递归

```
class Solution {
private:
	int cache[101][101];
public:
    int stoneGameII(vector<int>& piles) {
    	memset(cache, 0, sizeof(cache));

        int len = piles.size();
        vector<int> sum(len, 0);
        // 逆序部分和，方便查找出要拿的石头的大小
        sum.back() = piles.back();
        for(int i=len-2; i>=0; i--) sum[i] = sum[i+1] + piles[i];

        return helper(sum, 0, 1, len);
    }
    int helper(vector<int>& sum, int st, int M, int len){
    	// 剩下的可以一次拿完
    	if(2*M  >= len-st) cache[st][M] = sum[st];
    	if(cache[st][M] != 0) return cache[st][M];
    	int res = 0;
    	for(int X=1; X<=2*M; X++)
    		res = max(res, sum[st] - helper(sum, st+X, max(X, M), len));
    	cache[st][M] = res;
    	return res;
    }
};
```
动态规划代码

```
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int len = piles.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        vector<int> sum(len, 0);
        // 逆序部分和
        sum.back() = piles.back();
        for(int i=len-2; i>=0; i--) sum[i] = sum[i+1] + piles[i];
        // 倒着查找  dp[i][j] 代表当前在 i 位置，且此时 M = j-1  可以获得的最大收益
        for(int i=len-1; i>=0; i--)
            // 把可能情况都探索一遍，其中 M 的可能大小为 1 到 len
            for(int j=0; j<len; j++){
                // 剩下的点可以一次拿完
                int M = j+1;
                if(2*M >= len-i) dp[i][j] = sum[i];
                else{
                    // 一次拿不完的情况，取最大值
                    for(int k=1; k<=2*M; k++)
                        dp[i][j] = max(dp[i][j], sum[i]-dp[i+k][max(k, M)-1]);
                }
            }
        return dp[0][0];
    }
};
```

