### 解题思路
纯新人完全为了做出来，复杂度为n，求两个sum，sum1为所有字符对应数字相加之和，sum2为小在大前的字符之和，最后sum1-2*sum2就可以了，纯粹为了做出来，没有什么技术含量

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        sets={'I':1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        j=s[0]
        sum2=0
        sum1=0
        for i in s:
            if sets.get(i)>sets.get(j):
                sum2+=sets.get(j)
            sum1+=sets.get(i)
            j=i
        return sum1-2*sum2
                

            
```