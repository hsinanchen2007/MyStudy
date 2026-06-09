```
class Solution {
public:
    int hammingDistance(int x, int y) {
        return std::bitset<32>(x^y).count();
    }
};
```
