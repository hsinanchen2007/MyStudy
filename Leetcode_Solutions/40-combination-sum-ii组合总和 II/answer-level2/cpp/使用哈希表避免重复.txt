class Solution {
public:

    void dfs(vector<vector<int>>&res,vector<int>&tmp,map<int,int>&m,int target)
    {
        if(target==0)
        {
            res.push_back(tmp);
            return ;
        }
        if(target<0) return ;
        for(auto &c:m)
        {
            if(c.second==0||(tmp.size()&&c.first<tmp.back())) continue;
            c.second--;
            tmp.push_back(c.first);
            target=target-c.first;
            dfs(res,tmp,m,target);
            m[tmp.back()]++;
            target=target+tmp.back();
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>tmp;
        map<int,int> m;
        for(auto i:candidates) m[i]++;
        dfs(res,tmp,m,target);
        return res;
    }
};