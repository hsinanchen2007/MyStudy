### 解题思路
还是滑动窗口的方式，增加一个need来存储每个目标字符的计数。
1. 当前窗口是s[i：j]，结果窗口是s[I：J]。
2. 在need[c]中，存储了需要多少次字符c（可以为负），
3. 而missing则指示仍然缺少多少个字符。
4. 在循环中，首先将新字符添加到窗口中。
5. 然后，如果没有缺失，尽可能多地从窗口开始处删除字符，然后更新结果。

### Python3代码 (Python3不能高亮)
```python
from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # hash表存储目标字符的频次
        need = Counter(t)
        # 目标字符串的总长度
        missing = len(t)
        start, end = 0, 0
        i = 0
        # index j 从1开始，不是0
        for j, char in enumerate(s, 1):
            if need[char] > 0:
                missing -= 1
            need[char] -= 1
            # 所有字符匹配
            if missing == 0:
                # 移除字符找到真正的起始点
                while i < j and need[s[i]] < 0:
                    need[s[i]] += 1
                    i += 1
                # 确保第一个出现的char满足need[char]> 0
                need[s[i]] += 1
                # 错过了第一个字符，所以将missing加1
                missing += 1
                # 更新窗口
                if end == 0 or j - i < end - start:
                    start, end = i, j
                # 更新i到start+1开始下一个窗口
                i += 1
        return s[start:end]
        
```

### 结果
112 ms，排名80%