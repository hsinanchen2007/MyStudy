### 解题思路
利用HASH TABLE存储{letter,num},编写patternform函数，若字母之前存在于HT中，则返回其键对应的值num，否则（不存在于HT中），先将{letter,num}存到HT中，再返回num.

### 代码

```python3
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        def patternform(item):
            num,HT,res=1,{},""
            for letter in item:
                if letter in HT:#若字母存在于HASH TABLE中,取出num
                    res+=str(HT[letter])
                else:#若字母不存在于HASH TABLE中，先保存{letter,num},再取出num
                    HT[letter]=num
                    res+=str(num)
                    num+=1
            return res
        s_pattern=patternform(s)
        t_pattern=patternform(t)
        return True if s_pattern==t_pattern else False


```