### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        n = [1,5,10,50,100,500,1000]
        l = ['I','V','X','L','C','D','M']
        r = []
        k = []
        num1 = num
        for i in range(len(n)-1,-1,-1):
            if int(num1 / n[i]) == 0:
                r.append(0)
            else:
                r.append(int(num1 / n[i]))
                num1 = num1 - int(num1 / n[i]) * n[i]
        for j in range(len(r)):
            for m in range(r[j]):
                k.append(l[len(l) - j - 1])
        k = ''.join(k)
        while k.find('IIII') != -1:
            if k.find('VIIII') != -1:
                k = k.replace('VIIII', 'IX', 1)
            else:
                k = k.replace('IIII', 'IV', 1)
        while k.find('XXXX') != -1:
            if k.find('LXXXX') != -1:
                k = k.replace('LXXXX', 'XC', 1)
            else:
                k = k.replace('XXXX', 'XL', 1)
        while k.find('CCCC') != -1:
            if k.find('DCCCC') != -1:
                k = k.replace('DCCCC', 'CM', 1)
            else:
                k = k.replace('CCCC', 'CD', 1)
        
        return k
```