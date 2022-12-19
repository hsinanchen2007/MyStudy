### 解题思路
数学不好，只能算是暴力法的优化？害。

### 代码

```python3
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        result = []
        count = 1
        for i in range(1,n+1):
            if count == 15:
                result.append('FizzBuzz')
                count = 0
            elif count%5 == 0:
                result.append('Buzz')
            elif count%3 == 0:
                result.append('Fizz')
            else:
                result.append(str(i))
            count += 1
            
        return result
```