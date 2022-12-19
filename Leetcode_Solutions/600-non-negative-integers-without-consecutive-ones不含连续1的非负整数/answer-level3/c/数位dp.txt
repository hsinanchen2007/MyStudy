数位dp，要求是求其二进制不包含连续1的个数，可以考虑将整数转换成其二进制表示，然后使用二进制数位dp求解
```
#define MAX_LEN 31
int digits[MAX_LEN];
int dp[MAX_LEN][2][2][2][2];
int GetDigits(int num)
{
    int cnt = 0;
    if (num == 0) {
        digits[cnt++] = 0; 
    }
    while (num > 0) {
        digits[cnt++] = (num & 0x01);
        num >>= 1;
    }
    return cnt;
}
int dfs(int pos, int isOne, int isContinuesOnes, int limit, int lead)
{
    int up;
    int nxtLimit, nxtLead;
    int nxtIsContinuesOnes;
    int count = 0;
    if (pos < 0) {
        return isContinuesOnes ? 0 : 1;
    }
    if (dp[pos][isOne][isContinuesOnes][limit][lead] != -1) {
        return dp[pos][isOne][isContinuesOnes][limit][lead];
    }
    up = limit ? digits[pos] : 1;
    for (int i = 0; i <= up; i++) {
        nxtLimit = limit && i == up;
        nxtLead = lead && i == 0;
        nxtIsContinuesOnes = (isOne && i == 1) || isContinuesOnes;
        count += dfs(pos - 1, i, nxtIsContinuesOnes, nxtLimit, nxtLead);
    }
    return dp[pos][isOne][isContinuesOnes][limit][lead] = count;
}
int findIntegers(int num){
    int len;
    (void)memset(digits, 0, sizeof(digits));
    (void)memset(dp, -1, sizeof(dp));
    len = GetDigits(num);
    return dfs(len - 1, 0, 0, 1, 1);
}
```
