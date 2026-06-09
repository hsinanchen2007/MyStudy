### 解题思路
先判断字符串不为空，然后从第一个字符开始找，没有重复就赋值给co
找到第一个重复字母之后，将前面的co赋值给coo
然后从上次找到重复的字符的后一个字符开始找

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = 0
        co = ''
        coo = ''
        temp1 = 0
        temp2 = 0
        if s != '':
            while temp1 < len(s) and temp2 < len(s):
                if temp1>temp2:
                    temp2+=1
                elif temp1==temp2:
                    co = co + s[temp2]
                    temp2+=1
                elif s[temp2] not in co and temp2!=len(s)-1:
                    co = co + s[temp2]
                    temp2+=1
                elif s[temp2] not in co and temp2==len(s)-1:
                    co = co + s[temp2]
                    temp1 = len(s)
                    temp2 = len(s)
                elif s[temp2] in co and temp1 ==0:
                    coo = co
                    temp1 = temp1 + co.index(s[temp2]) + 1
                    temp2 = temp1
                    co = ''
                elif s[temp2] in co and temp1 !=0:
                    if len(co)>=len(coo):
                        coo = co
                        temp1 = temp1 + co.index(s[temp2]) + 1
                        temp2 = temp1
                        co = ''
                    else:
                        temp1 = temp1 + co.index(s[temp2]) + 1
                        temp2 = temp1
                        co = ''
            n = max(len(co),len(coo))
        return n
```