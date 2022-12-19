### 解题思路
常规解法，利用 % 与 if，elif 实现。

### 代码

```python3
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        num = []
        for i in range(1,n+1):
            if i%3 == 0 and i%5 == 0:
                num.append('FizzBuzz')
            elif i%3 == 0:
                num.append('Fizz')
            elif i%5 == 0:
                num.append('Buzz')
            else:
                num.append(str(i))
        return num 

```