```
class Solution {
public:
    int hammingDistance(int x, int y) {
        int out = x^y;
        int count = 0;
        while (out)
        {
            if (out & 0x1)
            {
                count++;
            }
            out = out >> 1;
        }
        return count;
    }
};
```