### 解题思路

计数，然后对各组cnt计算最大公约数，大于等于2即可。

### 代码

```cpp
constexpr int LENGTH = 10000;
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int cnt[LENGTH] = {0};
        for (int val : deck) cnt[val] ++;
        int cur = -1;
        for (int val : cnt) {
            if (val) {
                if (cur == -1) cur = val;
                else {
                    cur = __gcd(cur, val);
                }
            }
        }
        return cur >= 2 ? true : false;
    }
};
```