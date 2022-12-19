### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if x == 0:
            return 0
        x = str(x).rstrip('0')
        if x[0] in ['-', '+']:
            x = x[1:]
            return int('-' + x[::-1]) if int('-' + x[::-1]) in range(-2 ** 31, 2 ** 31) else 0
        else:
            return int(x[::-1]) if int('-' + x[::-1]) in range(-2 ** 31, 2 ** 31) else 0
```