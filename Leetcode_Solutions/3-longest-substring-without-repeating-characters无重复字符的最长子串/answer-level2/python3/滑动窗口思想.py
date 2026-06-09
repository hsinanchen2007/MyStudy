### 解题思路
其实质跟我之前写的小白方法一样，主要是一种思想吧！
ps:它的时间个空间都比小白算法的复杂（100ms:72ms;13.5MB:13.4MB)，我还是觉得之前那个小白算法易懂并且性能居然更优呢嘿嘿~

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:return 0
        left = 0
        lookup = []
        max_len = 0
        cur_len = 0
        for i in range(len(s)):
            cur_len += 1
            while s[i] in lookup:
                lookup.remove(s[left])
                left += 1
                cur_len -= 1
            if cur_len > max_len:max_len = cur_len
            lookup.append(s[i])
        return max_len

```