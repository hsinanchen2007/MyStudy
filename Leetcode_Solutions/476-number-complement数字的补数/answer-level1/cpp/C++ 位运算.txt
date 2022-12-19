```c++
class Solution {
public:
    int findComplement(int num) {
        int x = 0;
        int p = 0;
        while (num) {
            int b = num & 1;
            num >>= 1;
            x = x + !b * (1 << p++);
        }
        return x;
    }
};
```