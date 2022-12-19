### 解题思路
一定要先判断传入的参数，一定要先判断传入的参数，一定要先判断传入的参数！！！


### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0
        list = []
        p = 0
        for i in range(1, len(s)+1):
            if len(s[p:i]) == len(set(s[p:i])):
                if i == len(s):
                    list.append(s[p:i])
            else:
                list.append(s[p:i-1])
                c = s[i-1]
                index = s[p:i].index(c) + p
                p = index+1
        print(list)
        max_len = max([len(i) for i in list])
        return max_len
```