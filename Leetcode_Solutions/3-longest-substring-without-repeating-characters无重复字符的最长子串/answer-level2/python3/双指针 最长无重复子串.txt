### 解题思路
此处撰写解题思路

一开始的错误代码
```
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = j = 0
        l, res, char, tmp = len(s), 0, set(), 0
        while j<l:
            if s[j] not in char: 这个if其实是冗余的, 下面的while条件已经包括这个if了
                char.add(s[j])
                tmp += 1
            else:
                while s[j] in char:
                    i, tmp = i+1, tmp-1
                    char.remove(s[i])
                char.add(s[j]) # char add之后没有随之更新tmp. 其实可以直接用len(char)代替tmp
            res = max(res, tmp)            
            j += 1
        return res
```

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = j = 0
        l, res, char, tmp = len(s), 0, set(), 0
        while j<l:
            while s[j] in char:
                char.remove(s[i])
                i, tmp = i+1, tmp-1
            char.add(s[j])
            tmp += 1
            res = max(res, tmp)            
            j += 1
        return res
```