### 解题思路
![code.PNG](https://pic.leetcode-cn.com/ddbc2862da9ae4c55dee0b71d30a7b7165c80c26e6fdbd72ddf771f6fbe7926d-code.PNG)
遍历字符串，计算每个字符出现的次数，加到结果字符串后

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if S == '':
            return ''
        result = ''
        s = S[0]
        n = 0
        for i in S:
            if i == s:
                n+=1
            else:
                result += s+str(n)
                s = i
                n = 1
        result += s+str(n)
        if len(S)<=len(result):
            return S
        else:
            return result
```