```
class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i,j;
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end(),cmp);
        for(i=0;i<intervals.size();){
            int curl=intervals[i][0];
            int cure=intervals[i][1];
            int flag=0;
            for(j=i+1;j<intervals.size();j++){
                if(intervals[j][0]<=cure){
                    cure=max(cure,intervals[j][1]);
                    flag=1;
                }
                else break;
            }
            if(flag==0)i++;
            else{
                i=j;
            }
            res.push_back({curl,cure});
        }
        return res;
    }
};
```
o(n)