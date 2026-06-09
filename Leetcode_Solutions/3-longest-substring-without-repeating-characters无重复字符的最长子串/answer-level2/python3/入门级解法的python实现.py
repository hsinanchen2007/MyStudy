主要思路：使用一个列表，用于控制当前最长不重复子串。

1.定义midres列表，用于后续控制当前的最长不重复子串
  inmaxlen用于标记当前midere的长度
  maxlen用于标记整个过程当中最长不重复子串的长度
  starOfStr用于控制midres列表的左边位置
  i用于控制midres列表的右边位置

2.当列表左右位置未同时达到字符串右边界时，执行循环操作：
    1.如果位置i上的字符未出现在midres当中，则将i位置上的字符加入midres，并将midres长度+1
    （扩展midres列表的右边界）
    2.如果位置i上的字符已出现在midre当中，则删除midres当中的第一个元素，并将midres的左边界右移一位，
    将midres的长度-1

```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        midres = []
        lenOfStr = len(s)
        inmaxlen = 0
        maxlen = 0
        starOfStr = 0
        i = 0
        while i  < lenOfStr and starOfStr < lenOfStr:
            if not s[i] in midres:
                midres.append(s[i])
                inmaxlen = inmaxlen + 1
                if inmaxlen > maxlen:
                    maxlen = inmaxlen
                i = i + 1
            else:
                if inmaxlen > maxlen:
                    maxlen = inmaxlen
                del midres[0]
                inmaxlen = inmaxlen - 1
                starOfStr = starOfStr + 1
        return maxlen
```
