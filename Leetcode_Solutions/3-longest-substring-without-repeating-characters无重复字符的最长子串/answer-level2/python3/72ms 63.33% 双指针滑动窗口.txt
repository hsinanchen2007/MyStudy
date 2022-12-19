### 解题思路
此题使用两个指针表示滑动窗口的起始点和终止点，终止点逐渐右移，当新的字符与原窗口内部重复时，就删掉最左侧的字符（此时该字符一定是重复字符或位于重复字符左侧），直至窗口不再重复，并比较窗口大小

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = len(s)
        if l == 0:
            return 0
        ml = 1
        ms = set(s[0])
        # i为子串头部，j为子串尾部
        i = 0
        for j in range(1, l):
            while s[j] in ms:
                ms.remove(s[i])
                i += 1
            ms.add(s[j])
            ml = max(ml, j - i + 1)
        return ml
```