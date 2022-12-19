方法一：枚举出所有的二叉搜索树，然后返回对应的个数。

该方法可以，但没有必要。

方法二：数学演绎法，该题目中，不同的 n 的结果为对应的卡塔兰数，标记卡塔兰数为 G(n). 有：

![在这里插入图片描述](https://pic.leetcode-cn.com/c3056ec0c1f4d0e8138520e9edf8bd7bf94f17d54166371081623a7cb25b5156.png)

我们利用组合数字的求解方式，代入即可。

代码：
```cpp
class Solution {
public:
    //不同于上一题，这一道题并不需要找出所有的 BST.
    //只需要找出来个数即可：即 卡塔兰数
    int numTrees(int n) {
        long long ans = 1;
        for( int i = 1; i <= n; i++)
            ans = ans * ( n + i)/i;
        ans /= n+1;
        return ans;
    }
};

/*
求组合数 C(n, m) 的快速算法
long long fact(long long m,long long n){
    long long ans = 1;
    for(long long i = 1;i <= m;i++)
        ans=ans*(n-m+i)/i;
    return ans;
}
*/
```

