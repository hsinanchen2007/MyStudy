### 解题思路
//使用第一个字符串按字符串下标去和其他的字符串比较。全都符合的话游标移动一位直到发现不匹配的字符判断游标大于0的话就是最长的公共前缀。时间复杂度o(n)

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs):
        size = len(strs)
        if size == 0:
            return ""
        first = strs[0]
        if size == 1 or first == "":
            return first
        max = 0
        for i in range(len(first)):
            l = i + 1
            for j in strs:
                if first[:l] != j[:l]:
                    if max == 0:
                        return ""
                    else:
                        return first[:max]
            max = max + 1
        return first[:max]
```