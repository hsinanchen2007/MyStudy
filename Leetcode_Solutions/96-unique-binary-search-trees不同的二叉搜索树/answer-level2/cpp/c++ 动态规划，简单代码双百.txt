![Leetcode题解_1.jpg](https://pic.leetcode-cn.com/c815c42b696ad3051080d5e7448dac6ad9472ebc1a47e8cc1589d87e1d77a7c8-Leetcode%E9%A2%98%E8%A7%A3_1.jpg)

没有看大家的题解，都是自己琢磨的：

思路就是上图，不用关心具体二叉树怎么分配，只需要计算个数。
对于一个n=i，对里面的每一个值(例如x)都作为根结点，计算此时满足搜索二叉树的个数，那么这个根结点左右可分配的子树里分别是dp[x-1]和dp[i-x]，这两个dp的下标加起来是i-1,把dp[x-1]和dp[i-x]相乘。
这样对每一个n，其值dp[n]都可根据前面的dp值计算出来。
小细节：例如当n=4时，dp[3]需要两次（元素1和元素4的分配），所以可以设置dp[0]=2，统一代码形式；


```
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=2;
        dp[1]=1;
        for(int i=2;i<n+1;i++) {
            int tmp=0;
            for(int k=1;k<i;k++) {
                tmp+=dp[k]*dp[i-k-1];
            }
            dp[i]=tmp;
        }
        return dp[n];
    }
};
```
![hh.png](https://pic.leetcode-cn.com/1db89e7efffa2e117b4719332b8b780310f884bb0901afb51d85a4f58cf5a3ea-hh.png)
