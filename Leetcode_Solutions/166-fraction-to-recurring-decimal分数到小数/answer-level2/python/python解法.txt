### 解题思路
修改了很多次才做对，各种意外情况，都是泪啊

### 代码

```python
class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if numerator == 0:
            return str(0)
        if (numerator > 0) ^ (denominator > 0):
            zs_res = '-'
            numerator = abs(numerator)
            denominator = abs(denominator)
        else:
            zs_res = ''
            numerator = abs(numerator)
            denominator = abs(denominator)
        div_mod = []
        if numerator >= denominator:
            temp_div, temp_mod = divmod(numerator, denominator)
            if temp_mod == 0:
                zs_res += str(temp_div)
                return zs_res
            else:
                zs_res += str(temp_div) + '.'
                xiaoshubufen = temp_mod * 10
        else:
            zs_res += '0.'
            xiaoshubufen = numerator * 10
        flag = False
        while xiaoshubufen != 0:

            temp_div, temp_mod = divmod(xiaoshubufen, denominator)
            if (temp_div, temp_mod) not in div_mod:
                div_mod.append((temp_div, temp_mod))
            else:
                index = div_mod.index((temp_div, temp_mod))
                flag = True
                break
            xiaoshubufen = temp_mod * 10
        if not flag:
            for i in range(len(div_mod)):
                zs_res += str(div_mod[i][0])
            return zs_res
        else:
            for i in range(len(div_mod)):
                if i == index and flag:
                    zs_res += '('
                    zs_res += str(div_mod[i][0])
                    flag = False
                else:
                    zs_res += str(div_mod[i][0])
            zs_res += ')'
            return zs_res
```