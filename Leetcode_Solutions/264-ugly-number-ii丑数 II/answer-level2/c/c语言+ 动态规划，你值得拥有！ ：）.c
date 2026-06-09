### 解题思路
![image.png](https://pic.leetcode-cn.com/464126ea446cec3faedecdadb5b9cb27ce6280a4e8f10d334419e5d1017f41d4-image.png)


### 代码

```c
#define MIN(a,b) ((a < b) ? (a) : (b))

int min(int a ,int b,int c)
{
    int ret;
    ret = MIN(a,b);
    ret = MIN(ret,c);

    return ret;
}
int nthUglyNumber(int n){
    int dp[n];
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;
    int i;

    memset(dp,0,sizeof(int)*n);

    dp[0]=1;

    for(i = 1;i < n ;i++)
    {
        dp[i] = min(dp[i2]*2,dp[i3]*3,dp[i5]*5);

        if(dp[i] == dp[i2]*2)
        {
            i2++;
        }

        if(dp[i] == dp[i3]*3)
        {
            i3++;
        }

        if(dp[i] == dp[i5]*5)
        {
            i5++;
        }
    }

    return dp[i-1];
}
```