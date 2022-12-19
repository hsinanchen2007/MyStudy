### 解题思路
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.



### 代码

```c

#define MIN(a,b) ((a) < (b) ? (a):(b))
int mysqrt(int n){
    int min,max,mid;
    int sq;

    min = 1;
    max = n/2 +1;

    while(true){
        mid = (min + max)/2;
        sq = mid*mid;
        if(sq == n)
            return mid;
        else if(sq < n){
            if((mid+1) * (mid +1) > n)
                return mid;
            min = mid;
        }else if(sq > n)
            max = mid;
    }
    return 1;
}


int numSquares(int n){
    int i,j,k;
    int *dp;

    dp = malloc((n+1)*sizeof(int));

  
    for(i=1;i<=n;i++){
        dp[i] = n;
        k=1;
    #if 0
        while(k*k <= i)
            k++;
        k--;
    #else
        k = mysqrt(i);  
        //k = sqrt(i);
    #endif
        //printf("k=%d \n",k);
        if(k*k == i){
            dp[i] = 1;
            continue;
        }
    
        for(j=1;j<=k;j++){
            dp[i] = MIN(dp[i],dp[i-j*j] + 1);
        }
    }
    return dp[n];
}
```