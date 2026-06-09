### 解题思路
学过自动机的话就很简单了。
合法括号的文法是 `N->() | (N) | NN`
转换成dp就是 `dp[i] = "(" + dp[j] + ")" + dp[i-1-j]` （其中 j 从 0 到 i-1）

问为什么不能写成 `dp[i]= dp[j] + dp[i-j]` ？
因为会引起重复，比如 ()()() 这个序列会在 j=1 和 j=2 时被重复计算两次。
为什么上面的式子就不会引起重复了呢？留给读者思考。

附加题：求此题的空间和时间复杂度？

我觉得空间是$O(4^n)$，时间是$O(n^{1/2}*4^n+poly(n))$

### 代码

```python3
class Solution:
    def generateParenthesis(self, n):
        return (lambda dp:[dp.append(['('+k+')'+l for j in range(i+1)for k in dp[j]for l in dp[i-j]])for i in range(n)]and dp[n])([[""]])
```