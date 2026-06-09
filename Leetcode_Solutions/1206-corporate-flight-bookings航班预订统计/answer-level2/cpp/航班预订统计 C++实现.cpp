暴力超时，原来有一个思路，线段树，嫌麻烦。最后发现还是有大神的，参考 
https://leetcode-cn.com/problems/corporate-flight-bookings/solution/5118_hang-ban-yu-ding-tong-ji-by-user9081a/

C++实现，差异点：多申请一个位置，减少一次判断。

```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int end, value;
        vector<int> ret(n+1, 0);
        for (auto b: bookings) { ret[b[0]-1] += b[2], ret[b[1]] -= b[2]; }
        for (int i = 1; i < n; i++) { ret[i] += ret[i-1]; }
        ret.pop_back();
        return ret;
    }
};
```
