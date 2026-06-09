### 解题思路
直接切片，ans做循环内局部变量，遇到更大快乐前缀就覆盖

![image.png](https://pic.leetcode-cn.com/6dca46328026502277d605e40c23eb976a9b93a6fee67fc49535b656297a892f-image.png)


### 代码

```python3
class Solution:
    def longestPrefix(self, s: str) -> str:
        ans=''
        l=len(s)
        for i in range(l):
            if s[:i]==s[l-i:]:
                ans=s[:i]
        return ans


```