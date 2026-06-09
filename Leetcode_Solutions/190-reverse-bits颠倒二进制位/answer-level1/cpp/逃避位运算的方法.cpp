```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> n_bit(n);
        string s = n_bit.to_string();
        reverse(s.begin(), s.end());
        return stol(s, NULL, 2);
    }
};
```