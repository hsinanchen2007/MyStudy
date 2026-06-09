### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:

        if abs(x) > 2**31:
            return(0)

        sign = 1 if x > 0 else -1
        x_str = str(abs(x))

        result_abs = int(''.join([x_str[-1-i] for i in range(len(x_str))]))
        if result_abs > 2**31:
            return(0)

        return(sign*result_abs)


```