```
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        // set保证元素有序
        vector<set<string>> ans(n);
        // 依次合并
        for(int i=0;i<n;i++) {
            int idx = i;
            for(int j=0;j<i;j++) {
                if(ans[j].empty()) continue;
                for(int k=1;k<accounts[i].size();k++) {
                    if(ans[j].count(accounts[i][k])) {
                        idx = j;
                        break;
                    }
                }
                if(idx != i) break;
            }
            ans[idx].insert(accounts[i].begin()+1, accounts[i].end());
            // cout<<idx<<" "<<ans[idx].size()<<endl;
        }
        vector<vector<string>> res;
        for(int i=0;i<n;i++) {
            if(!ans[i].empty()) {
                vector<string> v(ans[i].begin(), ans[i].end());
                v.insert(v.begin(), accounts[i][0]);
                res.push_back(v);
            }
        }
        // res与accounts长度相等表示无合并操作，已达到最终状态，否则继续递归
        return res.size()==accounts.size()?res:accountsMerge(res);
    }
};
```
