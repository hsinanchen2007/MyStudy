
对于求给定范围的素数，常用筛法打表。

# 埃式筛法
从2开始作为基数，筛去其后基数的倍数。筛完后下一个剩余的数作为基数。
每次作为基数的数即是素数（除1外没有小于自身的因数）


```
void Eratosthenes(int maxn)
{
    int pc = 0;
    memset(vis, 0, sizeof(vis));
    memset(prime, 0, sizeof(prime));
    int m = sqrt(maxn + 0.5);
    for(int i = 2; i <= m; i++)
    {
        if(!vis[i])
        {
            prime[pc ++] = i;
            for(int j = i * i; j <= maxn; j += i)
                vis[j] = 1;
        }
    }
}
```
内循环可以看做是调和极数求和，数量级为O(logN)
总的时间复杂度在O(NlogN)

# 欧式筛法
埃式筛法做了很多重复的工作，如6在2和3做基数时都被筛了一次。
欧式筛法则是一个线性时间复杂度的筛法，不再仅以素数为基数，而是以所有的数为基数：

```
void Euler(int maxn)
{
    int pc = 0;
    memset(vis, 0, sizeof(vis));
    memset(prime, 0, sizeof(prime));

    for(int i = 2; i < maxn; i++)
    {
        if(!vis[i])
        {
            prime[pc ++] = i;
        }
        vis[i] = pc;
        for(int j = 0; j < pc; j++)
        {
            if(i * prime[j] > maxn) // 当乘积超过范围时结束本轮
                break;
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0)   // 当基数是某个已知素数的倍数，结束本轮
                break;
        }
    }
}
```
初始时素数列表为空，从2开始枚举
对于每一个基数，将其与已有素数按序相乘，筛去乘积
当乘积超过范围时结束本轮
当如果基数是某个已知素数的倍数，结束本轮
这样每个合数只会被枚举一次，并且一定会被枚举到，证明如下：

对于合数 k=m∗p1,p1 是其最小质因子，k 只会在 i=m,prime[j]=p1 时被枚举到
否则假设 k=n∗p2 且 p2>p1，有n<m，则 p1|n，那么在 i=n,prime[j]=p1 时便会结束，不会到 p2
欧式筛法的时间复杂度只有O(N)，目标范围越大相较于埃式筛法的优势越明显。