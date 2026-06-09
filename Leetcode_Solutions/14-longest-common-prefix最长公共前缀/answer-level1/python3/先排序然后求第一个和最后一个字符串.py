### 解题思路

先对字符串数组排序，然后暴力法求第一个字符串和最后一个字符串的最长公共前缀

不过这个方法的执行时间稍微偏长

执行用时 : 36 ms, 在所有 Python3 提交中击败了 85.25% 的用户
内存消耗 : 13.1 MB, 在所有 Python3 提交中击败了 91.31% 的用户

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ''

        strs.sort()	# 先排序后就只比较第一个和最后一个字符串的最长公共前缀
        first = strs[0]
        last = strs[-1]

        i = 0
        while i < len(first) and i < len(last) and first[i] == last[i]:
            i += 1
        return first[:i]
```