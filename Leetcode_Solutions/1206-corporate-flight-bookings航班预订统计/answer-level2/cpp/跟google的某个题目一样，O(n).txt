```
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n+1,0);
        for(auto b : bookings){
            res[b[0]-1] += b[2];
            res[b[1]]   -= b[2];
        }
        for(int i = 1;i < n; ++i){
            res[i] += res[i-1];
        }
        return vector<int>(res.begin(),res.end()-1);
    }
};
```