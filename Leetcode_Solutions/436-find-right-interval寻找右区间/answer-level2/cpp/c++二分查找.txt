```
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        vector<int> ans;
        for(int i=0;i<intervals.size();++i){
            vector<int> temp(intervals[i]);
            temp.push_back(i);
            v.push_back(temp);
        }
        sort(v.begin(),v.end(),[](const vector<int>& v1,const vector<int>& v2){
            return v1[0]<v2[0];
        });
        for(int i=0;i<intervals.size();++i){
            vector<int> vvv;
            vvv.push_back(intervals[i][1]);
            auto lala=lower_bound(v.begin(),v.end(),vvv,[](const vector<int>&v1,const vector<int>&v2){
                return v1[0]<v2[0];
            });
            if(lala==v.end())
                ans.push_back(-1);
            else
                ans.push_back((*lala)[2]);
        }
        return ans;
    }
};
```
