### 解题思路
这题各种流程和Corner case。现实中的业务代码也是各种Corner case啊。

1）先来一次mod，如果mod为0，那么运算结束
2）否则增加小数点
3）依次做除法运算，当可以得到非0的商时，记录mod。为什么要商非0时才记录mod，因为重复可能是多位数字，多位数字出现的规律就是商非0
4）发现有重复的mod，检查倒数两段是否是重复的。因为有可能mod重复，但是结果不重复，例如 1/6.
    如果重复，删除倒数第一段；如果不重复啥也不做
    之后为倒数第一段数字添加括号
5）判断要不要加负号

### 代码

```python
class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        num, divider = abs(numerator), abs(denominator)
        res, mod = divmod(num, divider)
        if mod == 0:
            result_str = str(res)
        else:
            result = []
            result.append(str(res))
            result.append(".")
            mod_map = {}
            while mod != 0:
                num = mod * 10
                res, mod = divmod(num, divider)
                result.append(str(res))
                if res != 0 and mod in mod_map:
                    rep_len = len(result) - mod_map[mod]
                    if "".join(result[-rep_len:]) == "".join(result[mod_map[mod] - rep_len:-rep_len]):
                        result = result[:-rep_len]
                        result.insert(mod_map[mod] - rep_len, "(")
                    else:
                        result.insert(len(result) - rep_len, "(")
                    result.append(")")
                    break
                if res != 0:
                    mod_map[mod] = len(result)

            result_str = "".join(result)

        if (numerator < 0 and denominator > 0) or (numerator > 0 and denominator < 0):
            result_str = "-" + result_str

        return result_str
```