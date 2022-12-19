### 解题思路

用一个额外的列表记录不重复的子串（滑动窗口）。注意在遇到重复字符串的时候，要将字符串从重复的位置截开。

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = []
        ans = 0
        for i in s:
            if i in res:
                ans = max(ans, len(res))
                index = res.index(i)
                res = res[index+1:]
            res.append(i)
        return max(len(res), ans)
```