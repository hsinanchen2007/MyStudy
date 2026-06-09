二叉搜索树有什么特点呢？
顶点左边的都比顶点的值小，顶点右边的都比顶点的值大
那么我们只要枚举一下哪一个数字作为顶点，就可以知道左边有几个数字，右边有几个数字，一定数量的连续数字对应的数结构是一样的，虽然数字不一样
{1,2,3}对应的二叉搜索树和{5,6,7}对应的二叉搜索树长得一样
![image.png](https://pic.leetcode-cn.com/91d04e3a2757837d0006c5998fc84b79e34bed1d9a2f214465062071b063ed95-image.png)

```
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);//dp[0] = 1 没有也是一种 
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            for(int j = 1; j <= i; j++)//哪一个做顶点
            {
                dp[i] += dp[j - 1] * dp[i - (j - 1) - 1]; 
            }
        }
        return dp[n];
    }
};
```
