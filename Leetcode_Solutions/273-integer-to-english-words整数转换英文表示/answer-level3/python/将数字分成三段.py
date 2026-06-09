### 解题思路
此处撰写解题思路
将数字分成三段 0 000 000 000 然后分别对每一段求再合并

### 代码

```python3
class Solution:
    def numberToWords(self, num: int) -> str:

        d = ["Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
             "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        d2 = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        bg = ["Billion", "Million","Thousand",'']
        if num==0:
            return d[0]
        def get_par(num):
            st = ''
            if num>=100:
                st +=d[(int(num/100))]+' Hundred '
                print(st)
                num = int(num%100)
            if num==0:
                    return st
            if num>=20:
                st +=d2[(int(num/10))]+' '
                num = int(num%10)
            print(num)
            if num==0:
                    return st
            st +=d[int(num)]+' '
            return st
        i=1000000000
        j=0
        sp = ''
        while i>0:
            if num>=i:
              print(get_par(num/i))
              sp +=get_par(num/i)+bg[j]+' '
              num %=i
            i = i/1000
            j+=1
        while sp[-1]==' ':
            sp = sp[:-1]
        return sp
            
```