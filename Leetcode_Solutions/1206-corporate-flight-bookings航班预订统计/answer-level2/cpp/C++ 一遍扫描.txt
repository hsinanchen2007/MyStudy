```
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n + 1, 0);
        for (auto& b : bookings) {
            res[b[0] - 1] += b[2];
            res[b[1]] -= b[2];
        }
        for (int i = 1; i < n; ++i) {
            res[i] += res[i - 1];
        }
        res.pop_back();
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/7b65b8ef1d0ac63056613615f7301f7db94e055448c7198041d31930fdd88c14-image.png)

