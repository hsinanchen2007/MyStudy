其实就是借助map来完成，详细思路见源代码
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;
        map<string,vector<string>> vec;
        if(strs.empty()) return res;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            vec[temp].push_back(strs[i]);
        }
        map<string,vector<string>>::iterator it;
        for(auto it=vec.begin();it!=vec.end();it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};
```
