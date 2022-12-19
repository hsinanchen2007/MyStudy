### 解题思路
从头到尾开始遍历

若遇到相同字符，则重新初始化到 上一个重复字符的下一位

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
    
        mark = dict()
        count = 0
        max_count = 0
        idx = 0
        s_len = len(s)

        while idx < s_len:
            if s[idx] in mark:
                if count > max_count:
                    max_count = count
                count = 0
                idx = mark[s[idx]] + 1
                mark.clear()
            else:
                count += 1
                mark[s[idx]] = idx
                idx += 1
        return count if count > max_count else max_count
```