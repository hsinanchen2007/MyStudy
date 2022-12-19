### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v1,v2;
        vector<vector<int>> tmp1,tmp2;
        vector<int> s;
        v2.push_back(nums);
        for(int x=0;x<nums.size();++x){
            v1.push_back({nums[x]});
            s=v2[0];
            s.erase(s.begin()+x,s.begin()+x+1);
            tmp2.push_back(s);
        }      
        v2=tmp2;
        tmp2.clear();
        
        for(int i=1;i<nums.size();++i){
            for(int j=0;j<v2.size();++j){
                for(int k=0;k<v2[0].size();++k){
                    s=v1[j];
                    s.push_back(v2[j][k]);
                    tmp1.push_back(s);
                    s=v2[j];
                    s.erase(s.begin()+k,s.begin()+k+1);
                    tmp2.push_back(s);
                }
            }
            if(i==0){
                for(int l=0;l<tmp1.size();++l){
                    tmp1[l].erase(tmp1[l].begin(),tmp1[l].begin()+1);
                }
            }
            v1=tmp1;
            v2=tmp2;
            tmp1.clear();
            tmp2.clear();
        }
        return v1;
    }
};
```