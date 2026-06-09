```
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string str = ::std::bitset<32>(n).to_string();
        ::std::reverse(str.begin(), str.end());
        return ::std::bitset<32>(str).to_ulong();
    }
};
```
