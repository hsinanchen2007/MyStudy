### 解题思路
利用异或运算。注意异或具有交换律和结合律。

### 代码

```python3
class Solution:
    def swapNumbers(self, numbers: List[int]) -> List[int]:
        # [a, b] -> [a^b, b]
        numbers[0] ^= numbers[1]
        # [a^b, b] -> [a^b, a^b^b] = [a^b, a]
        numbers[1] ^= numbers[0]
        # [a^b, a] -> [a^b^a, a] = [b, a]
        numbers[0] ^= numbers[1]
        return numbers
```