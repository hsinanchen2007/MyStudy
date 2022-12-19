### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> sortt;
        for(int i = 0;i<mat.size();i++){
            int cnt = 0;
            for(auto x:mat[i]){
                if(!x) break;
                cnt++;
            }
            sortt.push_back(pair(i,cnt));
        }
        sort(sortt.begin(),sortt.end(),[](pair<int,int> a,pair<int,int> b){
            if(a.second!=b.second)return a.second<b.second;
            return a.first<b.first;
        });
        vector <int> ret;
        for(int i = 0;i<k;i++){
            ret.push_back(sortt[i].first);
        }
        return ret;
    }
};
```