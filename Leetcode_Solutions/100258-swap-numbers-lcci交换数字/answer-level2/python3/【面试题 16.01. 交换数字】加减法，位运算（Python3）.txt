
## 加减法

存在溢出的可能。

```python
class Solution:
    def swapNumbers(self, numbers: List[int]) -> List[int]:
        numbers[0] = numbers[0] - numbers[1]
        numbers[1] = numbers[0] + numbers[1]
        numbers[0] = numbers[1] - numbers[0]
        return numbers
```

或者 


```python
class Solution:
    def swapNumbers(self, numbers: List[int]) -> List[int]:
        numbers[0] = numbers[0] + numbers[1]
        numbers[1] = numbers[0] - numbers[1]
        numbers[0] = numbers[0] - numbers[1]
        return numbers
```
## 位运算

我们考虑使用异或来解决。 异或的形式：

- 任何数 a 和本身异或等于 0，即 a ^ a 等于 0
- 0 和 任何数 a 异或，等于a，即 a ^ 0 等于 a

这样`numbers[0] ^ numbers[1] ^ numbers[0]` 就等于 numbers[1],`numbers[1] ^ numbers[0] ^ numbers[1]`就等于numbers[0]

```python
class Solution:
    def swapNumbers(self, numbers: List[int]) -> List[int]:
        return [numbers[0] ^ numbers[1] ^ numbers[0], numbers[1] ^ numbers[0] ^ numbers[1]] 
```
