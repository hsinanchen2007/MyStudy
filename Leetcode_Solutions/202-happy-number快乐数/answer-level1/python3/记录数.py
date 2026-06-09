### 解题思路
如果当前的数之前出现过则判断为循环，输出False

### 代码

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        record = []
        while n != 1:
            if n in record:
                return False
            record.append(n)
            cur = 0
            #generate next number
            while n !=0:
                cur += (n % 10)**2
                n = n//10
            n = cur
            #print(n)
        return True
```