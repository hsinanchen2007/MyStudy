```
class Solution {
public:
    bool static cmp(int &a,int &b){
        return a > b;
    }
    
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int,vector<int>> scores;
        vector<vector<int>> ans;
        
        for(auto m : items){
            scores[m[0]].push_back(m[1]);
        }
        for(auto s : scores){
            sort(scores[s.first].begin(),scores[s.first].end(),cmp);
        }
        for(auto s: scores){
            int sum = 0;
            for(int i = 0;i < 5; ++i){
                sum += s.second[i];
            }
            ans.push_back(vector<int>({s.first,sum/5}));
        }
        
        return ans;
    }
};
```