### 解题思路

借助0x55555555把对应的位拿下来交换就可以了。

### 代码

```cpp
class Solution {
public:
    int exchangeBits(int num) {
        int get = 0x55555555;
        int odd = num & get;
        int even = (num >> 1) & get;
        return odd << 1 | even;
    }
};
```