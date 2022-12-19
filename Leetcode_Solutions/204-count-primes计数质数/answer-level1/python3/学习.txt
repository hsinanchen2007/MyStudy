### 解题思路
此处撰写解题思路
去偶数去重复判断
### 代码

```python3
class Solution:
    def countPrimes(self, n: int) -> int:
        def isprimes(i):
            for j in range(3,int(i**0.5)+1,2):
                if i%j==0:
                    return 0
            return 1
                
        if n<=2:
            return 0
        count=1
        for i in range(3,n,2):
            count+=isprimes(i)
        return count

        
```