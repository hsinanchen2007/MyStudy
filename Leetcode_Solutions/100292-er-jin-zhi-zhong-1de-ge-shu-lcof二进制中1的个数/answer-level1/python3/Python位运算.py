### 解题思路
利用在二进制表示中，数字 n 中最低位的 1总是对应 n - 1 中的 0 。因此，将 n 和 n - 1 与运算总是能把 n 中最低位的 1 变成 0 ，并保持其他位不变。

### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n != 0:
            count += 1
            n = n&(n-1)
        return count
```