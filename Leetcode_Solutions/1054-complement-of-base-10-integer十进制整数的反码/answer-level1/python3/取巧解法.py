### 解题思路
取巧方法：通过观察我们可以发现，此题中N的二进制与二进制反码之和为其二进制长度length = （len(bin(N)[2:])）下的全“1”形式，转换为十进制即为 2 ** length - 1;
所以其二进制表示的反码所对应的十进制整数就为2 ** length - 1 - N，得解。

如有不对，请各位批评指出，谢谢！

### 代码

```python3
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        return 2 ** len(bin(N)[2:]) - 1 - N

```