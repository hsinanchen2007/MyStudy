### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        temp = ''
        len_ = 0
        for i in s:
            if i not in temp :
                temp +=i
                len_ = max(len_,len(temp))
            else:
                temp +=i
                temp = temp[temp.index(i)+1:]
        return len_
```