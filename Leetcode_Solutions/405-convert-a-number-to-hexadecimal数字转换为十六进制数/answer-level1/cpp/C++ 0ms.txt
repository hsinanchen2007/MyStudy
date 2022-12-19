```
class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string ret;
        constexpr char hex[] = "0123456789abcdef";
        unsigned int N = num > 0 ? num : 0x100000000 + num;
        while (N != 0) {
            ret = hex[N & 0b1111] + ret;
            N = N >> 4;
        }
        return ret;
    }
};
```
