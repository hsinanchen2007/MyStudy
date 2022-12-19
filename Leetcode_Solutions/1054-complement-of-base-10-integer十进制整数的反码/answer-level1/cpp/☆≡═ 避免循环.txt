1. 用对数函数 log2 获得 N 最高位 1 的位置。
2. 然后对1左移后减1，获得比N长度小1的掩码。
3. 将 N 取反，再和掩码与运算。

- 00000101 N
- 00000011 mask
- 00000010 (~N) & mask 

```c++
class Solution {
public:
    int bitwiseComplement(const int N) {
        if (N == 0) return 1;
        const int MSB = log2(N);
        const int mask = (1 << MSB) - 1;
        return (~N) & mask;
    }
};
```
