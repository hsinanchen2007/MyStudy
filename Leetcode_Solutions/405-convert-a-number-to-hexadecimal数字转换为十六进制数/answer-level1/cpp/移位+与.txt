```
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        string res;
        while (num) {
            int tmp = num;
            tmp &= 15;
            tmp < 10 ? res.push_back(tmp + '0') : res.push_back(tmp - 10 + 'a');

            num >>= 4;
            num &= ((1 << 28) - 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
