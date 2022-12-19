### 解题思路
没啥思路,就用暴力的了.

### 代码

```python3
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        List = []
        for i in range(1,n+1):
            if i%3 == 0 and i%5 == 0:
                List.append("FizzBuzz")
            elif i%3 == 0:
                List.append("Fizz")
            elif i%5 == 0:
                List.append("Buzz")
            else:
                List.append(str(i))
        return List
```