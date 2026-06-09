class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for (const auto &booking : bookings) {
            const auto &i = booking[0];
            const auto &j = booking[1];
            const auto &k = booking[2];
            ans[i - 1] += k;
            if (j < n) {
                ans[j] -= k;
            }
        }
        for (int i = 1; i < n; i++) {
            ans[i] += ans[i - 1];
        }
        return std::move(ans);
    }
};