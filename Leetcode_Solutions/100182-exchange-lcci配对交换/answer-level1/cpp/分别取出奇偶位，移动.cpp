

### 代码

```cpp
class Solution {
public:
    int exchangeBits(int num) {
        int even = 0b10101010101010101010101010101010;//0xAAAAAAAA
        int odd =   0b1010101010101010101010101010101;//0x55555555
        return ((num&even)>>1)^((num&odd)<<1);
    }
};
```