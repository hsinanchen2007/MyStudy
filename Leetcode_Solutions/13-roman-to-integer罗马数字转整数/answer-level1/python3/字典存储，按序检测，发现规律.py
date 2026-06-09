### 解题思路
用字典存储各个罗马数字字符对应的数值
从左至右检测到字符串的倒数第二个位置停止
    当前面的数字大于后方的数值时，总和累加上当前位置的数字
    如果小于，减去当前位置的数值，加上后一位的数字
循环结束后检测索引值是否小于字符串长度，即尾部的数字有没有漏加
若有则加上，返回总和sum

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        """
    将罗马数字转换成阿拉伯数字
    :param s:1~3999
    :return: int
    """
        rome_dict = {
            "M":1000,   "D":500,    "C":100,    "L":50,
            "X":10,     "V":5,      "I":1
        }

        sum = 0
        index = 0
        len = s.__len__()

        #从左至右循环扫描，扫描到字符串倒数第二个字符位置
        while index < (len-1):
            #取值的标准格式应该是rome_dict[s[index]]
            # 如果当前位置的字母对应的数值比后方字母对应的数字大，则加上当前字母对应的数值，并且索引后移一位
            if rome_dict[s[index]] >= rome_dict[s[index+1]]:
                sum += rome_dict[s[index]]
                index += 1
            else:
                # 如果小，则加上当前值减去后方值，并且索引后移两位
                sum = sum - rome_dict[s[index]] + rome_dict[s[index+1]]
                index += 2

        if index < len:
            sum += rome_dict[s[-1]]

        return sum
```