### 解题思路
将问题看成求状态(L,M,N,K)所对应的解，N和K为常量，题目已给出，L为还需要播放的歌曲数，M表示未播放的歌曲数，当L==M时，该状态的解为M！，L>M时，状态(L,M,N,K)的解分为两种情况，该状态下第一首歌是其他k首歌之前已经播放过的，可选择数是max(N-M-K,0)，(N-M表示已播放的，再减K表示K首歌以前，接着再取其和0的最大值);第二种情况为该状态下第一首歌是未播放的，可选择数是M个，所以不难得出，状态转移关系为L==M时，dp7(L,M,N,K)=M!;L>M时，
                     dp7(L,M,N,K)=dp7(L-1,M,N,K)*max(N-M-K,0)+M*dp7(L-1,M-1,N,K);
接着将每个状态存进dp数组中记录，下次需要时，不需要重复计算而直接查找即可，以达到剪枝目的。
### 代码

```cpp
class Solution {
public:
int mod = 1000000000 + 7;
int fact(long int M)
{
	long int re = 1;
	for (int i = 1; i <= M;i++)
	{
		re *= i;
		re %= mod;
	}
	return static_cast<int>(re);
}
int dp7(int**dp, int L, int M, int N, int K)
{
	if (L ==0)
		return 1;
	if (M < 0)return 0;
	if (L == M)
		return fact(M);
	else
	{
		if (dp[L][M] != -1)
			return dp[L][M];
		else
		{
			long long int res = 0;
			if (N - M > K)
                res +=static_cast<long long int>(N- M-K) *static_cast<long long int>( dp7(dp, L - 1, M , N, K));
				//res += (N - M - K)*dp7(dp, L - 1, M, N, K);这样写会爆int
                res%=mod;
			res +=static_cast<long long int>( M) *static_cast<long long int>( dp7(dp, L - 1, M - 1, N, K));
            res%=mod;
			dp[L][M] = res;
			return res;
		}
	}
}
    int numMusicPlaylists(int N, int L, int K) {
    int**dp = new int*[L+1];
	for (int i = 0; i <= L; i++)
	{
		dp[i] = new int[N+1];
		for (int j = 0; j <= N; j++) dp[i][j] = -1;
	}
	int res = dp7(dp, L, N, N, K);
	return res;
    }
};
```