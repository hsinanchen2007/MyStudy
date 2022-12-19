### 本题解参考自讨论区中Cmatrix用户的java题解
----
#### 为了表述方便，有如下约定：
1. N:任意整数（可以有多位，包括正负号，例如+1，-1, 1等等）
2. ()括起来的表述该部分可有可无
                                                                                                
则非科学计数法表示的数字（9、9.、9.9等等）可以表述为
Num1 = N((.(N))
或者
Num2 = .N

则科学计数法的数字可以表示为：
Num[Ee]N
or
Num2[Ee]N

翻译成正则即可。详情还得看正则表达式了。有些东西我不知道怎么表述。
```python
import re
class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip()  # 去除两端的空格
        pattern = r"^(([+-]?\d+(\.(\d+)?)?([Ee]([+-]?\d+))?)|([+-]?\.(\d+)([Ee][+-]?\d+)?))$"
        return True if re.match(pattern,s) else False
```
