1.dp[n]为以A[n]结尾的数组的最长湍流子数组长度
2.首个成员独自构成湍流数组所以dp[0]=0、第二个成员需要判断是否与第一个成员相等在A[0]==A[1]时是dp[1]=1否则为2
3.对于dp[n]判断A[x]~A[n-1]与A[n]是否组成湍流数组, 是则dp[i]=dp[i-1]+1;否则在A[i]==A[i-1]时dp[n]=1、在A[i]!=A[i-1]时dp[n]=2

```
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxTurbulenceSize(int* A, int ASize){
    if (A == NULL || ASize == 0) {
        return 0;
    }
    int i;
    int dp[ASize];
    dp[0] = 1;
    int max = dp[0];
    for (i = 1; i < ASize; i++) {
        if (i == 1) {
            dp[1] = (A[i] == A[i - 1] ? 1 : 2);
        } else {
            if (((A[i - 1] > A[i - 2]) && (A[i] < A[i - 1])) || ((A[i - 1] < A[i - 2]) && (A[i] > A[i - 1]))) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = (A[i] == A[i - 1] ? 1 : 2);
            }
        }
        max = MAX(max, dp[i]);
       //printf("dp[%d]=%d, max=%d\n", i, dp[i], max);       
    }
    return max;
}
```
