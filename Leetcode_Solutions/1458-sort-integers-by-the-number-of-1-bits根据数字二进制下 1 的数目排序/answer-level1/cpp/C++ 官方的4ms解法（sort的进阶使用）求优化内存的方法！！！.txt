```cpp
class Solution {
    #define N 10010
    int bit[N];
public:
    vector<int> sortByBits(vector<int>& arr) {
        for(auto x : arr) bit[x] = __builtin_popcount(x);
        sort(arr.begin(), arr.end(), [&](int x, int y) {
            return bit[x] == bit[y] ? x < y : bit[x] < bit[y];
        });
        return arr;
    }
};
```