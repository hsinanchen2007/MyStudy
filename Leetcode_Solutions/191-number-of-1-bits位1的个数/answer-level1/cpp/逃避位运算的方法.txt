```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> n_bit(n);
        string s = n_bit.to_string();
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '1') cnt++;
        return cnt;
    }
};
```