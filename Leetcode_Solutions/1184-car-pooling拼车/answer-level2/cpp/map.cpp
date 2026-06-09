
```
class Solution {
public:
    static bool cmp(vector<int> & a,vector<int> & b){
        return a[1] < b[1];    
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> carry;
        int n = trips.size();
        int rest = capacity;
        
        sort(trips.begin(),trips.end());
        for(int i = 0;i < n; ++i){
            carry[trips[i][1]] -= trips[i][0];
            carry[trips[i][2]] += trips[i][0];
        }
        for(auto t: carry){
            rest = rest + t.second;
            if(rest < 0){
                return false;
            }
        }
        
        return true;
    }
};
```