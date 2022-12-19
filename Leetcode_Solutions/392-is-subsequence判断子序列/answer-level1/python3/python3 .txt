### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        # 双指针
        # p1 = 0
        # p2 = 0
        # while p1 < len(s) and p2 < len(t):
        #     if s[p1] == t[p2]:
        #         p1 += 1
        #     p2 += 1
        # return p1 == len(s)
        
        # 使用库函数
        loc = -1
        for a in s:
            loc = t.find(a, loc+1)
            if loc == -1:
                return False
        return True

```