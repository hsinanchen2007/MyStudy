看到这个题目，第一感觉是动态规划法，其实只要n可以用奇数步走完的路径就能赢
先用递归进行求解
```
#define S_ODD  1
#define S_EVEN 0
int nim(int n)
{
	int dp1, dp2, dp3;
	if (n == 0) {
		return S_EVEN; 
	}
	if (n == 1 || n == 2 || n == 3) {
		return S_ODD; 
	}
	dp1 = nim(n - 1);
	dp2 = nim(n - 2);
	dp3 = nim(n - 3);
	/* 剩下的全都是奇数步，那么只能偶数步完成 */
	if (dp1 == S_ODD && dp2 == S_ODD && dp3 == S_ODD) {
		return S_EVEN;
	}
	return S_ODD;
}
bool canWinNim(int n){
	int cnt = nim(n);
	if (cnt == S_ODD) {
		return true;
	} else {
		return false;
	}
}
```
发现会超时，这时候一般是要保存中间结果，进行提速
dp[n] 代表 n是否可以有奇数步的解，dp[n] == S_ODD 代表存在，否则只有偶数步的解
```
#define S_ODD  1
#define S_EVEN 0
void nim(int n, int *dp)
{
	int dp1, dp2, dp3;
	if (dp[n] != INT_MAX) {
		return dp[n];
	}
	if (n == 0) {
		dp[0] = S_EVEN;
		return;
	}
	if (n == 1 || n == 2 || n == 3) {
		dp[1] = dp[2] = dp[3] = S_ODD;
		return;
	}
	nim(n - 1, dp);
	nim(n - 2, dp);
	nim(n - 3, dp);
	/* 剩下的全都是奇数步 */
	if (dp[n - 1] == S_ODD && dp[n - 2] == S_ODD && dp[n - 3] == S_ODD) {
		dp[n] = S_EVEN;
		return;
	}
	dp[n] = S_ODD;
	return;
}
bool canWinNim(int n){
	int *dp = NULL;
	int i;
	bool ret;
	
	if (n <= 3) {
		return true;
	}
	dp = (int*)calloc(n + 1, sizeof(int));
	for (i = 0; i <= n; i++) {
		dp[i] = INT_MAX;
	}
	nim(n, dp);
	ret = dp[n] == S_ODD ? true : false;
	free(dp);
	return ret;
}
```
发现大数不行，毕竟要分配非常大的dp，进行内存缩减
```
#define S_ODD  1
#define S_EVEN 0
bool canWinNim(int n){
	int i;
	int dp[3] = {S_ODD, S_ODD, S_ODD};
	int cur;
	int inx = 0;
	
	if (n <= 3) {
		return true;
	}
	
	for (i = 4; i <= n; i++) {
		if (dp[inx % 3] == S_ODD && dp[(inx + 1) % 3] == S_ODD && dp[(inx+2) % 3] == S_ODD) {
			cur = S_EVEN;
		} else {
			cur = S_ODD;
		}
		inx++;
		dp[(inx + 2) % 3] = cur;
	}
	return cur == S_ODD ? true : false;
}
```
居然还是超时，看来方法不对，打印dp出来发现是这样的规律[1,1,1,0,1,1,1,0...]
真是无语了...
```
bool canWinNim(int n){
	return n % 4;
}
```



