```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        int a = 10;
        int res = 1;
        while (n) {
            if (n&1) {
                res *= a;
            }
            n >>= 1;
            a *= a;
        }
        n = res - 1;
        vector<int> ans;
        for (int i = 1;  i < n + 1; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};
```