### 解题思路
制作几个列表来换取算法上的简单
### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        res = 0
        roman1 = ['I','V','X','L','C','D','M']
        num1 = [1,5,10,50,100,500,1000]
        roman2 = ['IV','IX','XL','XC','CD','CM']
        subnum = [2,2,20,20,200,200]
        for i in range(len(roman1)):
            res += num1[i]*s.count(roman1[i])
        for i in range(len(roman2)):
            if roman2[i] in s:
                res -= subnum[i]
        
        return res
```