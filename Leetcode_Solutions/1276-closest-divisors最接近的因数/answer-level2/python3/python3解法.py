### 解题思路
找出最大平方根之后逐次减一找出第一个可以被整除的数字

### 代码

```python3
class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        #求平方根
        def sqrt_root(num):
            sqrt = int(num**0.5+1)
            for i in range(sqrt,0,-1):
                if num % i == 0:
                    count = num // i 
                    return i,count
        num1,num2 = sqrt_root(num + 1)
        num3,num4 = sqrt_root(num + 2)
        if abs(num1-num2) > abs(num3-num4):
            return num3,num4
        else:
            return num1,num2


```