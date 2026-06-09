```
class Solution:
    def numberToWords(self, num: int) -> str:
        d = ["Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
             "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        d2 = ["Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        def zero_100(num):
            if num<20:
                return [d[num]]
            if num<=99:
                l = num % 10
                res = [d2[num // 10]]
                if l:
                    res += [d[l]]
                return res
        def hundred_1000(num):
            res = []
            h = num // 100
            l  = num % 100
            if h:
                res += [d[h], "Hundred"]
            if l:
                res += zero_100(l)
            return res
        
        if num == 0:
            return d[0]
        res = []
        for g, s in [[1000000000, "Billion"], [1000000, "Million"], [1000, "Thousand"], [1, ""]]:
            if num >= g:
                h = num // g
                res = res + hundred_1000(h) 
                if s:
                    res = res + [s]
                num = num % g
        return ' '.join(res)
            
```
优化代码
```
class Solution:
    def numberToWords(self, num: int) -> str:
        d = ["One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
             "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        d2 = ["Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        
        def zero_1000(num):
            if num<20:
                return d[num-1:num]
            if num<100:
                return  [d2[num // 10]] + zero_1000(num % 10)
            if num<1000:
                return [d[num // 100 - 1], "Hundred"] + zero_1000(num % 100)
        
        if num == 0:
            return "Zero"
        res = []
        for g, s in [[1000000000, ["Billion"]], [1000000, ["Million"]], [1000, ["Thousand"]], [1, []]]:
            if num >= g:
                res = res + zero_1000(num // g) + s
                num = num % g
        return ' '.join(res)
```
