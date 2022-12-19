```cpp
class Solution {
public:
    string generateTheString(int n) {
        string ans = "";
        if (!(n & 1)) ans += 's', --n;
        while (n--) ans += 'b';
        return ans;
    }
};
```