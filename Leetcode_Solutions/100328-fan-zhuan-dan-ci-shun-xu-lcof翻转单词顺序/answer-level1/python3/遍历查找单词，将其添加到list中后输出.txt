### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        word = ""
        lst = []
        for i in s:
            if i == ' ':
                if word!='':
                    lst.append(word)
                word = ""
            else:
                word = word + i
        if word != '':
            lst.append(word)
        res = ""
        for i in range(len(lst)-1,0,-1):
            res = res+lst[i]+' '
        if len(lst)>0:
            res = res + lst[0]
        return res
```