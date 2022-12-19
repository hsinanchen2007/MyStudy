### 解题思路
感觉可以一行处理完？还是写了很长

### 代码

```python3
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ret, temp1, temp2, temp3 = ['{}'.format(i + 1) for i in range(n)], -1, -1, -1
        for i in range(n // 3):
            temp1 += 3
            ret[temp1] = 'Fizz'
        for i in range(n // 5):
            temp2 += 5
            ret[temp2] = 'Buzz'
        for i in range(n // 15):
            temp3 += 15
            ret[temp3] = 'FizzBuzz'
        return ret

```