
### 通过字典，减少耗时
```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = -1
        max_len = 0
        d = {}
        # 遍历每个字符
        for i in range(len(s)):
            # 检查字符是否存在字典中，并且位置是否大于指针
            # d[s[i]] > start 相同字符更新指针位置
            if s[i] in d.keys() and d[s[i]] > start:
                start = d[s[i]]
                d[s[i]] = i
            else:
                d[s[i]] = i
                # 最新长度是否大于最大长度
                if i - start > max_len:
                    max_len = i - start
        return max_len
```
