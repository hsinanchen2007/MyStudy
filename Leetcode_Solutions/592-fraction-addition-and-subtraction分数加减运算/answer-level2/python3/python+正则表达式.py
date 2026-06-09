### 解题思路
先用正则表达式分割字符串，然后再求一下最小公倍数，最大公约数，再加减。

### 代码

```python3
class Solution:
    def fractionAddition(self, expression: str) -> str:
        #求最小公倍数
        def Least_common_multiple(a,b):
            a1,b1 = a,b
            res = a1 % b1
            while res != 0:
                a1 = b1
                b1 = res
                res = a1 % b1
            return int(a*b/b1)
        #求最大公约数
        def zuidagongyueshu(a,b):
            a1, b1 = a, b
            res = a1 % b1
            while res != 0:
                a1 = b1
                b1 = res
                res = a1 % b1
            return int(b1)
        #划分表达式
        import re
        string = re.findall(r'\d+/\d+',expression)
        yunsuanfu = re.findall(r'\d([+-])\d',expression)
        if expression[0] == '-':
            string[0] = '-' + string[0]
        res = []
        for item in string:
            res.append(item.split('/'))

        #求出所有分母的最小公倍数，把每一个分式换成分母相同
        help = int(res[0][1])
        for i in range(1,len(res)):
            help = Least_common_multiple(help,int(res[i][1]))
        for i in range(len(res)):
            res[i][0] = int(res[i][0]) * help // int(res[i][1])

        #求解加减运算
        a = res[0][0]
        res.pop(0)
        while yunsuanfu:
            fuhao = yunsuanfu.pop(0)
            s = res.pop(0)
            if fuhao == '+':
                a += s[0]
            else:
                a -= s[0]
        if a == 0:
            return '0/1'
        else:
            gys = zuidagongyueshu(abs(a), help)
            return '{0}/{1}'.format(a//gys,help//gys)
```