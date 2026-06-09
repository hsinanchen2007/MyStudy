### 解题思路
暴力法解法。
res数组保存最终的word数组，l记录字符长度。
1、遍历words数组，判断res数组是否为空，是就表明需要把当前word存入res
2、遍历res，判断当前word或者res里的值是否能从后往前匹配
    如果是的话，判断w和v的长度，更新res和l

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        res = []
        l = 0
        for w in words:
            wl = len(w)
            isAppend = False
            if len(res) == 0 :
                isAppend = True
            else:
                for i in range(len(res)):
                    v = res[i]
                    vl = len(v)
                    isMatch = False
                    if wl <= vl and w[-1] == v[-1] and w in v:
                        isMatch = True
                    elif wl > vl:
                        if w[-1] == v[-1] and v in w:
                            isMatch = True
                            l += (wl - vl)
                            res[i] = w
                    if isMatch:
                        isAppend = False
                        break
                    else:
                        isAppend = True
            if isAppend:
                l += (wl + 1)
                res.append(w)
        return l
```