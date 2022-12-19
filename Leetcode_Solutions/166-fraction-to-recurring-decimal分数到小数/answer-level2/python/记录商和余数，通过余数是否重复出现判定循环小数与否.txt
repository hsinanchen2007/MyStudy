### 解题思路
见标题

### 代码

```python
class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        def fraction_to_str(a, b):
            loop = False
            # 记录 余数 数组
            m = [a]
            r = []
            a = a * 10
            # 记录 商 数组
            r.append(a / b)
            a = a % b
            idx = 0
            while a:
                # 当 余数 重复出现的时候说明是循环小数，找到第一个循环余数出现的索引
                # 如 1 / 6 余数为 [1, 4, 4, 4, ...]
                # 因为初始的 a 也算是余数，所以前面有个 1，后续循环余 4，所以 idx = 1
                # 故 1 以前为不循环部分，1 以后为循环部分
                # 对应的商数组为 [1, 6, 6, 6, ...]， 所以有
                # ret1 = [1], ret2 = [6, 6, 6, ...]
                if a in m:
                    loop = True
                    idx = m.index(a)
                    break
                m.append(a)
                a = a * 10
                r.append(a / b)
                a = a % b
            ret1 = ''.join([str(_) for _ in r[0:idx]])
            ret2 = ''.join([str(_) for _ in r[idx:]])
            if loop:
                ret = ret1 + '(' + ret2 + ')'
            else:
                ret = ret1 + ret2
            return ret
        # 判定特殊情况
        if denominator == 0:
            return '+inf'
        if not numerator:
            return '0'
        # 归一化为正数运算
        ret = ''
        if numerator * denominator < 0:
            ret = '-'
        numerator = int(abs(numerator))
        denominator = int(abs(denominator))
        # 归一化为处理分数运算
        int_part = str(numerator / denominator)
        remainder = numerator % denominator
        if not remainder:
            return ret + int_part
        else:
            return ret + int_part + '.' + fraction_to_str(remainder, denominator)

```