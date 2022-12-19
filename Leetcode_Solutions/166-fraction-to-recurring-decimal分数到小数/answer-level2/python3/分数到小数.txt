### 解题思路
用基本的除法过程来进行计算；
1. 首先计算结果的整数部分；
2. 对于小数部分，一位一位的进行计算；在计算的过程中，同时保存小数位对应的分子；如果该分子在之前出现过，表明存在循环小数；
 
如`4/333`，整数部分为`0.`，第一个小数位为`0`，对应的分子为`4`；百分位为`1`，对应的分子为`40`；千分位为`2`，对应的分子为`67`；接下来的小数位为`0`，对应的分子为`4`，与十分位对应的分子相同；即循环小数部分从十分位开始；结果为`0.(012)`；
 
### 代码

```python3
class Solution:
    """
    用基本除法实现；如4/9，首先整数部分为0，然后十分位为40//9=4，余数仍为4；故结果为0.4，百分位为40//9，...，如此4即为循环；
    """
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        # 首先考虑分子与分母为0时的情况；
        if denominator == 0:
            return None
        if numerator == 0:
            return "0"
        
        # 将结果分成两个部分进行计算，其一是整数部分，其二是小数部分；
        # 1. 判断结果是否为负数；
        integral_part = ''
        if numerator*denominator < 0:
            integral_part += '-'
        # 2. 将分子分母将转换成正数进行考虑；
        numerator, denominator = abs(numerator), abs(denominator)

        # 3. 能完全整除直接返回；
        if numerator % denominator == 0:
            return integral_part + str(numerator//denominator)
        # 4. 否则计算整数部分，带小数点；
        elif numerator > denominator:
            integral_part += str(numerator//denominator)+'.'
            numerator = numerator % denominator
        else:
            integral_part += '0.'

        # 5. 单独计算小数部分；count表示从第几个小数开始循环；nume_dict用来保存相应的小数位置所对应的分子；
        # 如果该分子出现过，表明即从nume_dict[numerator]的位置开始循环；
        decimal_part = ''
        count = 0
        nume_dict = {numerator:count}
        while True:
            decimal_part += str(numerator*10 // denominator)
            numerator = numerator*10 % denominator
            # 6. 如果numerator为0，表明小数部分没有循环；直接返回；
            if numerator == 0:
                return integral_part+decimal_part
            count += 1
            # try except用来检查是否存在循环小数；
            try:
                index = nume_dict[numerator]
                decimal_part = decimal_part[:index]+'('+decimal_part[index:]+')'
                return integral_part+decimal_part
            except:
                nume_dict[numerator] = count
```