### 解题思路
思路都在**三行代码三行注释**里了，新手报道，欢迎大神些赐教咯。

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        import collections
        # 1.统计各字符次数，eg:"ddsad":[3, 1, 1]
        count = collections.Counter(s).values()
        # 2.统计两两配对的字符总个数，eg: {"ddass":4,"ddsss":4}
        x = sum([item//2*2 for item in count if (item//2 > 0)])
        # 3.判断是否有没配对的单字符，有结果加一。 eg: {"ddss":4, "ddhjSS":4+1}-->{"ddss":4, "ddhjSS":5}
        return x if x == len(s) else x+1
```