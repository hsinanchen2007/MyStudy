### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        if not s:
            return 0
        set_l = list(set(s))
        list_s = list(s)
        for i in set_l:
            if list_s.count(i) < k:
                list_s = list(s.replace(i,'0'))
        if '0' not in list_s:
            return len(list_s)

        sign = 1
        list_s.append('0') #最后面无法检测，增加哨兵
        while sign == 1:
            mi = 0
            sign = 0
            for i in range(len(list_s)):
                if list_s[i] == '0':
                    set_l = list(set(list_s[mi:i]))
                    for j in set_l:
                        if list_s[mi:i].count(j) < k:
                            if j != '0':
                                sign = 1           #加入新的才放入
                                list_s[mi:i] = list(s[mi:i].replace(j,'0'))
                    mi = i + 1

        list_s.pop()
        Max = 0
        mi = 0
        for i in range(len(list_s)):
            if list_s[i] == '0':
                Max = max(Max,mi)
                mi = 0
            else :
                mi += 1
        Max = max(Max,mi)
        return Max
```