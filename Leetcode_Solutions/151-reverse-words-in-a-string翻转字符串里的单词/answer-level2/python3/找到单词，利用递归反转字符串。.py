### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        lenth = len(s)
        def reverseWords(s, i):
            firstBlance = True
            tmp = ''
            while True:
                if i < lenth:
                    if s[i] == ' ':
                        if not firstBlance: break
                    else:
                        firstBlance = False
                        tmp += s[i]
                    i += 1
                else: return tmp
            left = reverseWords(s, i)
            return left + ' ' + tmp if left else tmp
        return reverseWords(s, 0) 


```