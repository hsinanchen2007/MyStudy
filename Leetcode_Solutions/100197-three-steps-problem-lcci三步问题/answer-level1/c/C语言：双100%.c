解题思想：比如走4阶台阶：
1. 先走1阶，剩下3阶，有4种走法
2. 先走2阶，剩下2阶，有2种走法
3. 先走3阶，剩下1阶，有1种走法
故共有4+2+1=7种走法，后面依此类推~~溢出问题，每次将和取模就行。
```
int waysToStep(int n){
    if (n==1) return 1;
    if (n==2) return 2;
    if (n==3) return 4;
    int a = 1, b = 2, c = 4, d;
    while (n>=4){
        d = ((a+b)%1000000007+c)%1000000007;
        a = b;
        b = c;
        c = d;
        n--;
    }
    return d;
}
```
或者用dp:
```
int waysToStep(int n){
    int dp[4] = {0};
    dp[0]=1, dp[1]=2, dp[2]=4;
    for (int i=3; i<n; i++){
        dp[i%3] = ((dp[(i-1)%3]+dp[(i-2)%3])%1000000007+dp[(i-3)%3])%1000000007;
    }
    return dp[(n-1)%3];
}
```

