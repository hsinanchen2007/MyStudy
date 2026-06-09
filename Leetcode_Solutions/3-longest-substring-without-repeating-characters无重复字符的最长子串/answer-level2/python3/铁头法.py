### 解题思路
用列表存储不重复序列，新建变量临时存储长度，遍历字符串，如果元素不包含在列表中，则在最后插入；如果存在，用当前列表长度与历史记录长度比较取最大值，之后清除重复元素以及重复元素之前的值，插入新元素。用时64ms，内存13.5MB

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = 0
        s1 = []
        for i in s:
            if i not in s1:
                s1.append(i)
            else:
                length = max(length, len(s1))
                index = s1.index(i)
                s1 = s1[index+1:]
                s1.append(i)
        return max(length, len(s1))
```