### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v1,v2,ans;
        sort(candidates.begin(),candidates.end());
        vector<int> newcd;
        for(int i=0;i<candidates.size();++i){
            if(candidates[i]>target) break;
            if(candidates[i]==target) {ans.push_back({target});break;}
            v1.push_back({0});
            v1[i][0]=candidates[i];
            newcd.push_back(candidates[i]);
        }
    
        vector<int> s;
        while(v1.size()!=0){
            for(int j=0;j<v1.size();++j){
                for(int k=0;k<newcd.size();++k){
                    s=v1[j];
                    s.push_back(newcd[k]);
                    if(accumulate(s.begin(),s.end(),0)==target) {ans.push_back(s);break;}
                    if(accumulate(s.begin(),s.end(),0)>target) break;
                    v2.push_back(s);
                }
            }
            v1=v2;
            v2.clear();
        }
        for(int i=0;i<ans.size();++i){
            sort(ans[i].begin(),ans[i].end());
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());  
        return ans;
    }
};
```