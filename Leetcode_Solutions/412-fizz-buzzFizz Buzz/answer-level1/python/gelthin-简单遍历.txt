### 解题思路
简单遍历即可

这一题避免冗余判断，官方题解值得深思。


### 代码

```python3
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        i, j = 0, 0
        result = []
        for k in range(1, n+1):
            i += 1
            j += 1
            if i==3 and j==5:
                result.append('FizzBuzz')
                i, j = 0, 0
            elif i==3:
                result.append('Fizz')
                i = 0
            elif j==5:
                result.append('Buzz')
                j = 0
            else:
                result.append(str(k))
        return result
```