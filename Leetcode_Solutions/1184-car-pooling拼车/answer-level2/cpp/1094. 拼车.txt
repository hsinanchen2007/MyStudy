```
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> tmp(1001,0);
        for(vector<int>& trip:trips)
        {
            tmp[trip[1]]+=trip[0];
            tmp[trip[2]]-=trip[0];
        }

        int guest=0;
        for(int& t:tmp)
        {
            guest+=t;
            if(guest>capacity)return false;
        }
        return true;
    }
};
```
