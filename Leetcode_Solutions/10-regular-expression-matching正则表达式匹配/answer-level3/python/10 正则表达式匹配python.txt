### 解题思路
递归方法。
 
![image.png](https://pic.leetcode-cn.com/12c56b8ae6da738965ca2d2419959ba93d6dfe97924b7d06fba82f6181575e5b-image.png)

### 代码

```python
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if not p:
            return not s

        first_match = bool(s) and p[0] in {s[0], '.'}

        if len(p) >= 2 and p[1] == '*':
            return (self.isMatch(s, p[2:]) or
                    first_match and self.isMatch(s[1:], p))
        else:
            return first_match and self.isMatch(s[1:], p[1:])

```

### 解题思路
动态规划。
 
![image.png](https://pic.leetcode-cn.com/ee3daf3acb5a88e8d61716e31431012177624033be322b2f8e2d828299fc2905-image.png)

### 代码

```python
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        memo = dict() # 备忘录
        def dp(i, j):
            if (i, j) in memo: return memo[(i, j)]
            if j == len(p): return i == len(s)

            first = i < len(s) and p[j] in {s[i], '.'}
            
            if j <= len(p) - 2 and p[j + 1] == '*':
                ans = dp(i, j + 2) or \
                        first and dp(i + 1, j)
            else:
                ans = first and dp(i + 1, j + 1)
                
            memo[(i, j)] = ans
            return ans
        
        return dp(0, 0)

```