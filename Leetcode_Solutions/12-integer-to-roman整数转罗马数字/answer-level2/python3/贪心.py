不用注释，直接降序排列，速度更快点。
```
class Solution:
    def intToRoman(self, num: int) -> str:
        # d={1:'I',4:'IV',5:'V',
        #     9:'IX',10:'X',
        #     40:'XL',50:'L',
        #     90:'XC',100:'C',
        #     400:'CD',500:'D',
        #     900:'CM',1000:'M'}
        # ls=list(sorted(zip(d.keys(),d.values()),reverse=True))

        ls=[(1000,'M'),(900,'CM'),(500,'D'),(400,'CD'),(100,'C'),
            (90,'XC'),(50,'L'),(40,'XL'),(10,'X'),(9,'IX'),(5,'V'),
            (4,'IV'),(1,'I')]
        res=''
        for k, t in ls:
            while num >= k:
                res += t
                num = num - k
        return res
```
