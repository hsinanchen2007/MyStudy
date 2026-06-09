```
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        if(folder.empty()) return ans;
        if(folder.size() ==1&&folder[0].size() !=1) return vector<string>{folder[0]};
        sort(folder.begin(),folder.end());
        int pre = 0;
        int next = 1;
        ans.push_back(folder[0]);
        while(next < folder.size())
        {
            if(folder[next].find(folder[pre]) == 0&&folder[next].size() > folder[pre].size()&&folder[next][folder[pre].size()] == '/') {next++;}
            else 
            {
                ans.push_back(folder[next]);
                pre = next++;
            }
        }
        return ans;

    }
};
```
