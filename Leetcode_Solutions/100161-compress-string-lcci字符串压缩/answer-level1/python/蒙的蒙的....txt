### 解题思路
遍历一遍，一个一个比较就行，内存100%真是没想到...

### 代码

```python
class Solution(object):
    def compressString(self, S):
        l = len(S)
        sum = 1
        temp = "aa"
        str1 = ""
        for i in range(0,l):
            if S[i] != temp:
                str1 += str(sum)
                str1 += S[i]
                temp = S[i]
                sum = 1
            else:
                sum += 1
        str1 += str(sum)
        if len(str1[1:]) >= l:
            return S
        else:
            return(str1[1:])
```