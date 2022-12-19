### 解题思路
考虑首位数字：
如果首位是1，如1234，考虑1XXX等于1234-1000+1加上小于234的次数；考虑0XXX等于3*10^2（某位是1，其余位0-9，三种情况）。
如果首位大于1，如4567，考虑1XXX有10^3；考虑4XXX，有小于567的次数；考虑(0|1|2|3)XXX,有4乘XXX出现1的次数。

### 代码

```python3
class Solution:
    def countDigitOne(self, n: int) -> int:
        if n<=0:
            return 0
        def countdigitstr(num:str):
            if len(num)==1:
                return min(int(num),1)
            elif int(num[0])==1:
                return int(num[1:])+1+countdigitstr(num[1:])+(len(num)-1)*10**(len(num)-2)
            elif int(num[0])==0:
                return countdigitstr(num[1:])
            else:
                return countdigitstr(num[1:])+10**(len(num)-2)*((len(num)-1)*int(num[0])+10)
        return countdigitstr(str(n))
```