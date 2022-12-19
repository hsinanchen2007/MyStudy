```
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        map<string,vector<string>> res;
        for(int n = 0; n < paths.size(); n++)
        {
            istringstream is(paths[n]);
            string s;
            is>>s;
            string m;
            while(is>>m)
            {
                int k = m.find('(');
                if(res.find(m.substr(k,-1)) == res.end())
                    res[m.substr(k,-1)] = vector<string>{s+'/'+m.substr(0,k)};
                else
                    res[m.substr(k,-1)].push_back(s+'/'+m.substr(0,k));
            }
        }
        for(auto f:res)
        {
            if(f.second.size() >1) ans.push_back(f.second);
        }
        return ans;
    }
};
```
