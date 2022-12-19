### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        # if s == '': return -1

        # max_idx = len(s)
        # dic = {}

        # for idx, s_ in enumerate(s):
        #     if dic.setdefault(s_, idx) != idx: dic[s_] = max_idx
        # min_idx = dic[min(dic.keys(),key=(lambda x:dic[x]))]
        
        # return [-1, min_idx][min_idx < max_idx]
        from collections import Counter
        dic = Counter(s)
        for i in range(len(s)):
            if dic[s[i]] == 1: return i
        return -1 
```