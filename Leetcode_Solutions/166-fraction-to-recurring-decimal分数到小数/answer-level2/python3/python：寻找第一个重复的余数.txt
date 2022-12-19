模拟一次除法就可以得到这道题的计算过程，记录每次出现的余数，一旦下一次借位后的带余除法得到的余数与记录的字典发生了重合，那么可以判定：从整个余数上一次出现的位置带现在的位置————这部分发生了循环。
话不多说，直接贴出来，输出的细节还是很多的，我提交了几次才过，尤其是python在除数被除数符号不同时的除法运算和c++还有题目的规定是不一样的


```python []
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        flag = 1 if numerator*denominator>=0 else -1
        numerator = abs(numerator)
        denominator = abs(denominator) #python对于负数的除法依然是向下取整，题中的要求是按照绝对值除法余数的，所以取绝对值
       
        head = numerator//denominator
        head = str(head) if flag>0 else '-'+str(head)

        rest = numerator%denominator
        res = []
        rest_dic = {}  #注意到余数只能取0(除尽了),1,2,....denominator-1这么多情况,用字典计算余数出现的最后一次位置，一旦发生了重复代表从余数上一次在字典中记录的位置开始发生了循环
        ind = 0
        while(rest!=0 and rest not in rest_dic):          
            rest_dic[rest] = ind
            rest *= 10
            res.append(str(rest//denominator))
            rest = rest%denominator
            ind += 1

        if not res:
            return head
        if rest==0:
            return head+'.'+''.join(res)
        else:
            return head+'.'+''.join(res[:rest_dic[rest]])+'('+''.join(res[rest_dic[rest]:])+')'
```

