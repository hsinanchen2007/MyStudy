### 解题思路
我的思路是，首先对列表按照其字母长度排序，然后循环每次把所有单词的同一位字母放到一个集合中（利用集合元素不可重复的原理），最终确定集合长度。如果集合只有一个字母，说明所有单词该位置的字母都相同，提取其中字母并加入到空字符串中，继续下一位字母比较。如果集合长度不为一，说明该位单词有不同字母，终止循环并返回之前的字符串。

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ''
        i = 0
        ls_final = ''
        strs = sorted(strs, key=lambda x:len(x))
        for i in range(len(strs[0])):
            ls = set()
            for str in strs:
                ls.add(str[i])
            if len(ls) == 1:
                ls_final += ls.pop()
            elif len(ls) != 1:
                break
        return ls_final
```