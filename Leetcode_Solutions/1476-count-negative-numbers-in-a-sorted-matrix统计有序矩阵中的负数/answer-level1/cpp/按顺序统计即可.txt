暴力
```class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(auto v : grid){
            for(auto c : v){
                if(c < 0){
                    count++;
                }
            }
        }
        return count;
    }
};
```