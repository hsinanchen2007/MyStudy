### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        from collections import defaultdict
        lookup = defaultdict(int)
        for c in t:
            lookup[c] += 1

        start = 0
        end = 0
        min_len = float("inf")
        counter = len(t)
        res = ""
        while end < len(s):
            if lookup[s[end]] > 0:   ###s的元素在t中
                counter -= 1     
            lookup[s[end]] -= 1      ###t对应元素减一，如果无对应，则不减
            end += 1                 #后移
            while counter == 0:      ###找对对应子串，判断最小长度
                if min_len > end - start:
                    min_len = end - start
                    res = s[start:end]
                if lookup[s[start]] == 0:  #重新回复字典
                    counter += 1
                lookup[s[start]] += 1
                start += 1
        return res


```