### 解题思路
根据题意，压缩后字符长度最少等于len(set(S))的两倍，先排除，再判断，先记录字符的第一个字母，次数一次。
遍历字符，比对当前字符是否与前一位相同，相同加一，不同记录下上一位的次数，和当前字符。
最后，返回记得加上最后一位字母出现的次数
比对长度是否变短，再输出

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if len(set(S)) * 2 >= len(S):
            return S
        result = 1
        s = S[0]
        for i in range(1,len(S)):
            if S[i] == S[i-1]:
                result += 1
            else:
                s = s + str(result) + S[i] 
                result = 1
        if len(s + str(result)) >= len(S):
            return S
        return s + str(result)
```