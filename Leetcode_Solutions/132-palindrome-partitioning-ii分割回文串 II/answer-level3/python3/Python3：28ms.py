### 解题思路
1. 分奇数和偶数数量分割回文
2. 找到每个回文的最大半径

### 代码

```python
class Solution(object):
    def minCut(self, s):
        # 加速，2特例：字符串本来就是回文，一次分割的情况
        if s == s[::-1]:
            return 0
        for i in range(1, len(s)):
            if s[:i] == s[:i][::-1] and s[i:] == s[i:][::-1]:
                return 1
        # 给分割数（cut）赋初始值
        cut = [x for x in range(-1, len(s))]
        print(cut, cut[-1])
        for i in range(len(s)):
            r1, r2 = 0, 0
            # 找到最大的回文半径
            # 奇数回文
            while i-r1 >= 0 and i+r1 < len(s) and s[i-r1] == s[i+r1]:
                cut[i+r1+1] = min(cut[i+r1+1], cut[i-r1]+1)
                r1 += 1
            # 偶数回文
            while i-r2 >= 0 and i+r2+1 < len(s) and s[i-r2] == s[i+r2+1]:
                cut[i+r2+2] = min(cut[i+r2+2], cut[i-r2]+1)
                r2 += 1
            print(cut, cut[-1])
        return cut[-1]
```