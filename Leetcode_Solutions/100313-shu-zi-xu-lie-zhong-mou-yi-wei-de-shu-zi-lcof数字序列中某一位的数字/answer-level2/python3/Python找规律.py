### 解题思路
先找出第n位应该是哪个数字的第几位再返回。

### 代码

```python3
class Solution:
    def findNthDigit(self, n: int) -> int:
        i = 1 #位数
        n -= 1
        while n - i*9*10**(i-1) > 0:
            n -= i*9*10**(i-1) #超出个数
            i += 1
        num = 10**(i-1)
        target = num + n//i
        return int(str(target)[n%i])
        
        
```