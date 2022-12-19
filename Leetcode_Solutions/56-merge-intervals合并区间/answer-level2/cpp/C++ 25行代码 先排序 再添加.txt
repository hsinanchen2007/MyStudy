```
class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> ret;
        
        for(int i=0;i<intervals.size();i++){
            if(i == 0){
                ret.push_back(intervals[i]);
                continue;
            }
                
            int ret_last_index = ret.size()-1;
            if(ret[ret_last_index][1] >= intervals[i][0]){
                ret[ret_last_index][1] = max(ret[ret_last_index][1],intervals[i][1]);
            }else{
                ret.push_back(intervals[i]);
            }  
        }
        return ret;
    }
};
```
