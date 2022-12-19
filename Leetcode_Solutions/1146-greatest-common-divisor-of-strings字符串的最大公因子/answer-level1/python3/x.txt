### 解题思路
执行用时 :36 ms, 在所有 Python3 提交中击败了82.57% 的用户
内存消耗 :13.4 MB, 在所有 Python3 提交中击败了5.88%的用户

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""
        def gcd(m, n):
            return m if n == 0 else gcd(n, m % n)
        m, n =len(str1), len(str2)
        return str1[:gcd(m, n)]
```