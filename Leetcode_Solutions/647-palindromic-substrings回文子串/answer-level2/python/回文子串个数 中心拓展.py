### 解题思路
感觉中心拓展的思路对于回文子串更合适
124 ms
, 在所有 Python3 提交中击败了
83.99%

### 代码

```python3
class Solution:
    def countSubstrings(self, s: str) -> int:
        def solve(i, j):
            nonlocal res
            while i>=0 and j<l and s[i]==s[j]:
                i -= 1
                j += 1
                res += 1 # 不同开始结束位置都算一个新的回文子串
        res, l = 0, len(s)
        for i in range(l):
            solve(i, i) # 奇数
            solve(i, i+1) # 偶数
            
        return res
```