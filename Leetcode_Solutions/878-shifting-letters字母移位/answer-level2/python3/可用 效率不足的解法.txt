key1：越靠前的字母需要移位越多次    ~   数组逆序求和
key2：移位数字 与 原来字母与'a'的距离 之和 对26取余即可得到最终的移位数字
key3：ascII码与字符的转换          ~   通过 ord()   chr() 函数

```
class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        import numpy as np
        result = ""
        for i in range(1,len(shifts)+1):
            if i == 1 :
                shifts[-i] = shifts[-i]
            else : 
                shifts[-i] += shifts[-i+1] 
        for j in range(0,len(shifts)):
            result += chr( ord('a')+ (ord(S[j]) - ord('a') + shifts[j])%26 )
        return result
```
代码效率有待提升