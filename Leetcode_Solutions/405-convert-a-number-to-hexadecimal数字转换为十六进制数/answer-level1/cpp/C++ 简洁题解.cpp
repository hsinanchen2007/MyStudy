```
class Solution {
public:
    char m[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    string toHex(int num) {
        if (num == 0)
            return "0";
        string res;
        uint32_t n = num;
        while (n > 0) {
            res += m[n - ((n >> 4) << 4)]; // 即 m[n % 16]
            n >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/723a384858d71449136a1f552942ca77f2e806547b8d144f69fda26ce150c153-image.png)
