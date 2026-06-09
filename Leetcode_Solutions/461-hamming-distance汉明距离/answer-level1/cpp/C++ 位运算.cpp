```
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while (x > 0 || y > 0) {
            if ((x ^ y) % 2 == 1)
                ++res;
            x = x >> 1;
            y = y >> 1;
        }
        return res;
    }
};
```
