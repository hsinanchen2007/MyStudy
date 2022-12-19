### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if abs(x) < 10:
            return x
        num_list = []
        abs_x = abs(x)
        while abs_x > 0:
            m, n = divmod(abs_x, 10)
            num_list.append(n)
            abs_x = m
        if x < 0:
            num_list = [-1 * i for i in num_list]
        y = 0
        for i in range(len(num_list)):
            y *= 10
            y += num_list[i]
        if abs(y) >= 2 ** 31 - 1:
            return 0
        return y
```