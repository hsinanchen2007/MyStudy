### 解题思路
简单的逐位判断

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        ans = ''
        for i in range(num // 1000):
            ans += 'M'
            num -= 1000
            
        if num >= 900:
            if num // 900:
                ans += 'CM'
                num -= 900
        elif num >= 500:
            ans += 'D'
            num -= 500
        elif num >= 400:
            ans += 'CD'
            num -= 400
        # 注意每次最小位都要判断，并不与前面是互斥关系
        if num >= 100:
            for i in range(num // 100):
                ans += 'C'
                num -= 100
        
        if num >= 90:
            if num // 90:
                ans += 'XC'
                num -= 90
        elif num >= 50:
            ans += 'L'
            num -= 50
        elif num >= 40:
            ans += 'XL'
            num -= 40
        if num >= 10:
            for i in range(num // 10):
                ans += 'X'
                num -= 10 
                
        if num >= 9:
            if num // 9:
                ans += 'IX'
                num -= 9
        elif num >= 5:
            ans += 'V'
            num -= 5
        elif num >= 4:
            ans += 'IV'
            num -= 4
        if num >= 1:
            for i in range(num // 1):
                ans += 'I'
                num -= 1
        
        return ans
```