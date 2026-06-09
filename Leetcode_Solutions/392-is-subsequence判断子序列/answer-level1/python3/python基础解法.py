### 解题思路
1. 第一种思路是双指针来求解，判断s[0]是否等于t[i]里面，当存在的情况下去判断s[1]是等于t[i+1],最后判断长度是否相等即可。
2. 第二种方法是在题解里面看到的运用迭代器和生成器去判断是否存在。感谢@leacoder的题解，速度快了不少。

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        # i, j = 0, 0
        # while i < len(s) and j < len(t):
        #     if s[i] == t[j]:
        #         i += 1
        #         j += 1
        #     else:
        #         j += 1
        # return i == len(s)

        b = iter(t)
        return all((i in b) for i in s)
                
```