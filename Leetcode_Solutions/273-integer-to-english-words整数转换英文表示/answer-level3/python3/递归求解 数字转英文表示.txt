- 20以内的数字可以直接转换
- 100 以内的可以分为整除十的部分和各位部分
- 1000以内可以分为整百部分和 其余部分
- 10**6 次方可以整除一千分为两部分 递归求解
- ......
```
class Solution:
    def numberToWords(self, num: int) -> str:
        d1=['','One','Two','Three','Four','Five','Six','Seven','Eight','Nine','Ten','Eleven','Twelve','Thirteen','Fourteen','Fifteen','Sixteen','Seventeen','Eighteen','Nineteen','Twenty']
        d2=['','Ten','Twenty','Thirty','Forty','Fifty','Sixty','Seventy','Eighty','Ninety']

        e1 = ['Zero','One','Two','Three','Four','Six','Seven','Eight','Nine','Ten','Eleven','Twelve','Thirteen','Fourteen','Sixteen','Seventeen','Eighteen','Nineteen','Twenty']
        e2 = ['','Ten','Twenty','Thirty','Forty','Fifty','Sixty','Seventy','Eight','Ninety']

        if num == 0: return 'Zero'
        if num <= 20:
            return d1[num]
        if num < 100:
            t,d=num//10,num%10
            return d2[t] +' '+d1[d] if d>0 else d2[t]
        
        if num < 1000:
            t,d = num//100,num%100
            if d==0: return d1[t] + ' Hundred'
            return d1[t] + ' Hundred ' + self.numberToWords(d)
        
        if num < 10**6:
            t,d = num//1000,num%1000
            if d==0: return self.numberToWords(t) + ' Thousand'
            return self.numberToWords(t) + ' Thousand ' + self.numberToWords(d)
        
        if num < 10**9:
            t,d = num//10**6,num%10**6
            if d==0: return self.numberToWords(t) + ' Million'
            return self.numberToWords(t) + ' Million ' + self.numberToWords(d)
        
        if num < 10**12:
            t,d = num//10**9,num%10**9
            if d==0: return self.numberToWords(t) + ' Billion'
            return self.numberToWords(t) + ' Billion ' + self.numberToWords(d)
```
