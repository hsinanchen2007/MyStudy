简单解释一下,我觉得在计数时增加判断太消耗操作数了，而且考虑起来太麻烦
不如直接计数，然后针对ol取最小值/2
针对abn直接取最小值
然后取上面两个的最小值，这不用解释吧
```
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        dct = {'a': 0, 'b': 0, 'l': 0, 'o': 0, 'n': 0}
        for i in text:
            if i in dct:
                dct[i] += 1
        dou = int(min(dct['o'], dct['l'])/2)
        sin = min(dct['a'], dct['b'], dct['n'])
        return min(dou, sin)
```
