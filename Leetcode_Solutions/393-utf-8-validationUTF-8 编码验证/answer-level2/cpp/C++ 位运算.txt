```cpp
class Solution {
public:
    int oneCount(int n) {
        for (int i = 7; i >= 0; --i) {
            if ((n & (1 << i)) == 0)
                return 7 - i;
        }
        return 8;
    }
    bool validUtf8(vector<int>& data) {
        const int ONE = 1 << 7; // 10000000
        const int TWO = 3 << 6; // 11000000
        int k = 0;
        for (auto n : data) {
            if (k == 0) {
                if ((n & TWO) == ONE)
                    return false;
                if (n & ONE) {
                    k = oneCount(n);
                    if (k > 4)
                        return false;
                    --k;
                }
            } else {
                if ((n & TWO) != ONE)
                    return false;
                --k;
            }
        }
        return k == 0;
    }
};
```
