![image.png](https://pic.leetcode-cn.com/fa5dd48f8c34bd80143197719db0fa53deeb656a3d571fa6c26dc71ad21f0b65-image.png)

### 解题思路
设T(n)为输入为n时的结果数。
在n = 某个k时，以根为分界线，所有情况就是根左子树总节点数0~k-1，对应的右字数总节点数k-1~0,也就是加起来是k-1个。
**只要把左子树情况乘右子树情况数再加起来就行了**
即T(k) = （从i=0~k-1累加）(T(i)*T(k-1-i))
为了不像无脑递归Fibonacci数列那样爆炸，就用一个数组存下来就好了
### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        int dp[n+1], temp;
        dp[0] = 1;
        for(int i = 1; i < n+1; ++i)
        {
            temp = 0;
            for(int j = 0; j < i; ++j)
                temp += dp[j]*dp[i-j-1];
            dp[i] = temp;
        }
        return dp[n];
    }
};
```