### 解题思路
1. 分别取出数字二进制奇数位和偶数位
2. 将奇数位的二进制放在偶数位（即右移
3. 将偶数位的二进制放在奇数位（即左移

### 代码

```cpp
class Solution {
public:
    int exchangeBits(int num) {
        int even = (num & 0xaaaaaaaa) >> 1;
        int odd = (num & 0x55555555) << 1;
        return even | odd;
    }
};
```