### 解题思路
此处撰写解题思路
先将所有的位数计算出来；
再进行字符串的拼接，在这个过程中要留意６个特殊的规则，将６个规则的逻辑写通顺即可
### 代码

```python3
class Solution:
    def intToRoman(self, num):

        m_num = int(num / 1000)
        d_num = int((num - m_num * 1000) / 500)
        c_num = int((num - m_num * 1000 - d_num * 500 ) / 100)
        l_num = int((num - m_num * 1000 - d_num * 500 - c_num * 100) / 50)
        x_num = int((num - m_num * 1000 - d_num * 500 - c_num * 100 - l_num * 50) / 10)
        v_num = int((num - m_num * 1000 - d_num * 500 - c_num * 100 - l_num * 50 - x_num * 10) / 5)
        i_num = num - m_num * 1000 - d_num * 500 - c_num * 100 - l_num * 50 - x_num * 10 - v_num * 5

        result = 'M' * m_num 
        if c_num == 4:
            if d_num == 1:
                result = result + 'CM'
            else:
                result = result + 'CD'
        else:
             result = result + 'D' * d_num + 'C' * c_num
        if x_num == 4:
            if l_num == 1:
                result = result + 'XC'
            else:
                result = result + 'XL'
        else:
             result = result + 'L' * l_num + 'X' * x_num
        if i_num == 4:
            if v_num == 1:
                result = result + 'IX'
            else:
                result = result + 'IV'
        else:
             result = result + 'V' * v_num + 'I' * i_num
        return result
```