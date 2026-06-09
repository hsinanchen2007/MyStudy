基于评论区大佬的思想做的

将n节点的树 分为i和n-i-1两个子树

同时i取值为0~n-1

迭代相加即可

为什么用的乘而不是+   如果左2右2 两边各2的话 总方法就有4种

```
/**
 * @param {number} n
 * @return {number}
 */
var numTrees = function(n) {
    // 0子树情况要置为1  
    let dp=[1,1,2];
    for(let i =3;i<=n;i++)
        {
            dp[i]=0;
            for(let j=0;j<i;j++)
                {
                    // 由于 一个i节点的可以分割为 左边j，右边i-j-1  因此可能的种类就是j的情况*i-j-1的情况
                    // 其中j取值可以是0~i-1
                    dp[i]+=(dp[j]*dp[i-j-1])
                }
        }
    return dp[n]
};
```