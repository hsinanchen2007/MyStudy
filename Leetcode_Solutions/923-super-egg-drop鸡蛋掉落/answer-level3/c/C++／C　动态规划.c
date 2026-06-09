
见代码注释

```
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int>(N+1));
        //dp[i][j]表示 有i个鸡蛋、j次扔鸡蛋次数时可以测的最多楼层，扔鸡蛋次数最多不会超过N次（线性扫描）
        //case base:
        //dp[0][...] = 0;
        //dp[...][0] = 0;
        //默认初始化数组为0
        int m = 0;
        //要得到至少需要的最多扔鸡蛋机会，先初始化为0次
        while (dp[K][m] < N) {
            ++m;
            for (int j = 1; j <= K; ++j) {
                dp[j][m] = dp[j - 1][m - 1] + dp[j][m - 1] + 1;
                //假设在某一层扔了一个鸡蛋，碎了：鸡蛋个数减1，机会减1；没碎：机会减1。
            }
        }
        return m;
    }
};
```


```
int fun(int K, int T)	// 计算 K 个鸡蛋，扔 T 次，可以覆盖多少个区间
{
	if (T == 1 || K == 1) 
        return T + 1;
	return fun(K - 1, T - 1) + fun(K, T - 1);
}

int superEggDrop(int K, int N) 
{
	int T = 1;	// 扔鸡蛋的机会
	while (fun(K, T) < N + 1) 
        T++;
	return T;
}
```
