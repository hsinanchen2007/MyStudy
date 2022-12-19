### 解法1：递归
### 解题思路
类似与斐波那契数列，直接暴力递归，辅以记忆化字典。

![image.png](https://pic.leetcode-cn.com/02f4f3198cc9c169799c1d40537315299973338b7e091173ff7c813e7b0824a9-image.png)


### 代码

```python
ans = {0:0, 1:1, 2:1}
class Solution(object):
    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        if n in ans:
            return ans[n]
        else:
            ans[n] = self.tribonacci(n-1) + self.tribonacci(n-2) + self.tribonacci(n-3)
            return ans[n]
```

### 解法2：动态规划
### 解题思路
一般用递归可以做的，用动态规划也可以做，时间复杂度O(n)，空间复杂度O(n)

![image.png](https://pic.leetcode-cn.com/d47b80eab50283be214c2a943a369f9b8f85452d7c6086679d9fc83548eb0633-image.png)

### 代码

```python
class Solution(object):
    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = [0, 1, 1]
        if n<3:
            return ans[n]
        for index in range(3,n+1):
            ans.append(sum(ans[index-3:index]))
        return ans[n]
```
