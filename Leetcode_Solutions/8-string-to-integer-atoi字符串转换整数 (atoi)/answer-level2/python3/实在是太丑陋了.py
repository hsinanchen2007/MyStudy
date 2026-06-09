这实在是太丑陋了，搞这么多奇怪的输入有什么用啊。
**守住不用正则的底线！**
结果本来很简洁，被各种奇葩输入逼成了这样：
```python []
class Solution:
    def myAtoi(self, s: str) -> int:
        
        # 去掉两边的空格
        s = s.strip()
        # 全空格，无效
        if not s:
            return 0
        # 单个非数字字符，无效
        if len(s) == 1 and not s[0].isnumeric():
            return 0
        # 以数字、+、-以外的字符开头，无效
        if not s[0].isnumeric() and s[0] != '-' and s[0] != '+':
            return 0
        # 提取加减号
        # 加减号提取后仍然以非数字开头，无效
        neg = False
        if s[0] == '-':
            neg = True
            s = s[1:]
            if not s[0].isnumeric():
                return 0
        elif s[0] == '+':
            s = s[1:]
            if not s[0].isnumeric():
                return 0
        # 从左往右提取连续的数字
        numbers = ''
        i = 0
        while i < len(s) and s[i].isnumeric():
            numbers += s[i]
            i += 1 
        # 加上正负号并处理溢出（真是傻逼用python还要处理溢出）
        value = int(numbers)
        if neg:
            if value > 2147483648:
                return -2147483648
            else:
                return 0 - value
        else:
            if value > 2147483647:
                return 2147483647
            else:
                return value
```
哎嘿没想到还算挺快的~ 
直觉告诉我还有合并步骤优化的空间，不过反正都是`O(n)`，懒得弄了。
不想做的同学拿去抄吧，反正做了也没有什么意义。