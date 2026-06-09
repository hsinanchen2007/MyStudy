## 思路:

思路一：模拟

思路二：数学方法

$n = \frac{(x + 1) * x}{2}$ (等差求和公式)

$x^2 + x = 2n$

$x^2 + x + \frac{1}{4}-\frac{1}{4} = 2n$

$(x + \frac{1}{2})^2 = 2n + \frac{1}{4}$

$(x + \frac{1}{2})^2 = \frac{8n+1}{4}$

$x + \frac{1}{2} = \frac{\sqrt{8n+1}}{2}$

$x = \frac{\sqrt{8n+1}}{2}-\frac{1}{2}$

$x = \frac{\sqrt{8n+1} - 1}{2}$

## 代码:

思路一：

```python
class Solution:
    def arrangeCoins(self, n: int) -> int:  
        i = 1
        while n - i >= 0:
            n -= i
            i += 1
        return i - 1
```

思路二：

```python
class Solution:
    def arrangeCoins(self, n: int) -> int:  
        return int(((8 * n + 1) ** 0.5 - 1) // 2)
```

