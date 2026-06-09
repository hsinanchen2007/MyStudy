### 代码

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32>temp(n);
        uint32_t res = 0;
        for(int i = 0; i < 32; i++)
        {
            //cout<<temp[i];   //bitset左边是二进制的低位
            res = res*2 + temp[i];  
        }
        return res;
    }
};
```