### 解题思路
此处撰写解题思路
可以分析，1-n每个值都可以做根节点，比如x做了节点，那么小于x的只能在左树中，大于x的在右树中。
不论数值范围是多少，1-5也好，4-9也好，只要范围内数字个数相同，产生的二叉搜索树的种类数就相同，因而有状态方程：
f(n, x)=f(x-1)+f(n-x) x属于1-n
f(n)=Sigma(f(n, x))
初始状态：f(0)=1
在这个题之前先刷了“不同的二叉搜索树II”，在那里学到了一个static修饰符的用法，在这里用了一下。

### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        if(n<0) return 0;
        static vector<int> dp(1, 0);
        int o_size=dp.size();
        if(n+1>dp.size()) dp.resize(n+1);
        dp[0]=1;
        for(int i=o_size; i<=n; i++){
            dp[i] = 0;
            for(int root=1; root<=i; root++){
                int left=root-1, right=i-root;
                dp[i] += dp[left]*dp[right];
            }
        }
        return dp[n];
    }
};
```