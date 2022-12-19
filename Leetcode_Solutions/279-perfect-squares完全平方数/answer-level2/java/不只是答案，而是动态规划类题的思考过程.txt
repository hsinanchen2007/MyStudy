动态规划是自顶向下的思考过程，一般不那么容易
那么，先考虑暴力应该怎么做，那就是递归啦，可以画一个图来助于理解
![image.png](https://pic.leetcode-cn.com/cdb92652df762994f5e6ebb8d4507b3d57b615eb1c46b7f87c64a0b82292328c-image.png){:width=500}

因为这么暴力递归会有很多重叠子问题重复计算，所以加一个记忆化步骤，使得不再重复计算。

**自顶向下，记忆化搜索**
```java
int[] memo;
public int numSquares(int n) {
    memo = new int[n+1];
    return numSqu(n);
}

private int numSqu(int n){
    if (memo[n]!=0)
        return memo[n];
    int val = (int)Math.sqrt(n);
    if (val*val==n){
        return memo[n] = 1;
    }
    int res = Integer.MAX_VALUE;
    for (int i = 1;i*i<n;i++){
        res = Math.min(res, numSqu(n-i*i)+1);
    }
    return memo[n] = res;
}
```

**递推关系我们也清楚之后，我们就理解啦，就可以自底向上写DP了**
```java
public int numSquares(int n) {
    int[] memo = new int[n+1];
    for (int i = 0;i<=n;i++)  memo[i]=i;

    for(int i = 2;i<=n;i++){
        for (int j = 1;j*j<=i;j++){
            memo[i] = Math.min(memo[i],memo[i-j*j]+1);
        }
    }
    return memo[n];
}
```


