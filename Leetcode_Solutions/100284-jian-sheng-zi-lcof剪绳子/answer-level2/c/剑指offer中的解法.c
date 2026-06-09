### 解题思路
剑指offer中的解法

### 代码

```c
int cuttingRope(int n){
    if(n==2)
    return 1;
    if(n==3)
        return 2;
    //动态规划中n-i是可以>=0的，因为最后已经剪过了，可以不减拿来直接用的。所以
    int out[n+1];
    out[0]=0;
    out[1]=1;
    out[2]=2;
    out[3]=3;   //out的前四个值存的是f(n-i),可以不切割直接用的，后面的对应f(n)
    int max=0;
    for(int i=4;i<=n;i++)
    {
        max=0;
        for(int j=i;j>0;j--)
        {
            if(max<j*out[i-j])
                max=j*out[i-j];
        }
        out[i]=max;
    }
    return out[n];
}
```