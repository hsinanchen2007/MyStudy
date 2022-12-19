### 解题思路
遍历每个字符，遇到相同的字符count+1，直到遇到不同的字符，count清0。
需要注意的是要判断当j=len(S)-1的时候，也就是来到最后一个字符的时候，也要把count加上去，否则直接跳出了循环。

### 代码

```python
class Solution(object):
    def compressString(self, S):
        """
        :type S: str
        :rtype: str
        """
        if S == '':
            return S
        len_s = len(S)
        result = ''
        i = 0
        while i < len_s:
            result=result+S[i]
            count = 0
            for j in range(i,len_s):
                if S[j] == S[i]:
                    count = count + 1
                else:
                    result = result + str(count)
                    break
                if j == len_s-1:
                    result = result + str(count)
            i = i + count
        if len(result)<len_s:
            return result
        else:
            return S
```