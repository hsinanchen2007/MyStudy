### 解题思路
最开始写了个o(n^2)的代码，一个一个赋值，超时了；就想到不能一个一个赋值，既然不能一个一个赋值，那么肯定得做一个标记，也即是说需要在区间的开始和结束分别加上或减少K，最后在遍历一次数组，计算出每个位置的ans即可。

### 代码

```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nextSin(n, 0);
        for (auto item : bookings) {
            nextSin[item[0] - 1] += item[2];
            if (item[1] < n) {
                nextSin[item[1]] -= item[2];
            }
        }
        int currentCount = 0;
        vector<int> ans(n, 0);
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = nextSin[i] + currentCount;
            currentCount = ans[i];
        }
        return ans;
    }
};
```