### 解题思路
1、先对字符串批量处理，使他们与第一串的长度相同
2、将第一个字符串的前缀与之后的字符串进行比较，设置最长前缀的右边界，如果碰到不满足条件的字符串，右边界减一
3、结束

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0: return ""
        right = len(strs[0])
        j = 0
        for i in range(1, len(strs)):
            if len(strs[i]) >= right:
                strs[i] = strs[i][0:right]
            else:
                strs[i] = strs[i] + " " * (right - len(strs[i]))
        while j < len(strs):
            while right > 0:
                if strs[0][0:right] != strs[j][0:right]:
                    right -= 1
                else:
                    break
            j += 1
        return strs[0][0:right]
```