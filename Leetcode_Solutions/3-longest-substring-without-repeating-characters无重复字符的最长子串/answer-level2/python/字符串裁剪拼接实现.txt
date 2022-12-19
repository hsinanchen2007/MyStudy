### 解题思路
小白第一次交题有点紧张, 大佬们有优化的可以分享下给我。
这里主要是定义一个子串, 遍历传入的字符串。
如果当前字符不在子串中则作拼接,如存在子串中则从起始位置开始裁剪。

### 代码

```python3
from collections import Counter


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 判断整条串无重复的情况 sp: porce
        count = Counter(s)
        _check = lambda num: True if num == 1 else False
        if False not in map(_check, count.values()):
            return len(s)

        max_num, sub_string = 1, s[0:1]
        for _ in s[1:]:
            while True:
                if _ not in sub_string or not sub_string:
                    break
                sub_string = sub_string[1:] if len(sub_string) > 1 else ""
            sub_string += _
            max_num = len(sub_string) if len(sub_string) > max_num else max_num
        return max_num


s = Solution()
result = s.lengthOfLongestSubstring("porce")
print(result)
```