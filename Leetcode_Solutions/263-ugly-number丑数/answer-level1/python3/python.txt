### 解题思路
记录一个last加快速度，如果一轮循环过后数字不变，直接返回false

### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        if num<=0:
            return False
        while num!=1:
            last=num
            if num%2==0:
                num//=2
            if num%3==0:
                num//=3
            if num%5==0:
                num//=5
            if num==last:
                return False
        return True
```