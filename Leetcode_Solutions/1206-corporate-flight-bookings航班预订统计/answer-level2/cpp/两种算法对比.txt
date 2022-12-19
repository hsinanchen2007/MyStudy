```
//超时算法
class Solution1 {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for (int i = 0; i < bookings.size(); i++) {
            for (int j = bookings[i][0]; j <= bookings[i][1]; j++) {
                ans[j - 1] += bookings[i][2];
            }
        }
        return ans;
    }
};

//通过算法
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        vector<int> add(n, 0);
        vector<int> reduce(n, 0);
        for (int i = 0; i < bookings.size(); i++) {
            int start = bookings[i][0];
            int end = bookings[i][1];
            add[start - 1] += bookings[i][2];
            reduce[end - 1] += bookings[i][2];
        }

        ans[0] = add[0];
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i-1] + add[i] - reduce[i - 1];
        }
        return ans;
    }
};
```
