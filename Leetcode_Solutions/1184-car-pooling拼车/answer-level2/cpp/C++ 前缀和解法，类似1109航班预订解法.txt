class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> ans(1001, 0);
        for (auto &t : trips) {
            ans[t[1] - 1]  += t[0];
            ans[t[2] - 1] -= t[0];  //到站就下车了，所以下标ans[t[2] - 1],区别于1109题
        }
         
        for (int i = 1; i < 1001; ++i) {
            ans[i] += ans[i - 1];
        }

        for( int i=0; i<1001; i++) {
            if(ans[i]> capacity) {
                return false;
            }
         }

        return true;
    }
};