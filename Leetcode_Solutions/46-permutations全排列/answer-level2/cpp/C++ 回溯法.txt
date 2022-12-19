直接回溯就行，需要说明的是我用bitset来代替bool数组标记已访问的数据。下面是我的代码：
```
class Solution {
public:
    vector<int> tmpans;
    vector<vector<int>> ans;
    bitset<20> s;
    void dfs(vector<int>& nums,int t)
    {
        if(nums.size()==t)
            ans.push_back(tmpans);
        for(int i=0;i<nums.size();i++)
        {
            if(s[i]==1)
                continue;
            s[i]=1;
            tmpans.push_back(nums[i]);
            dfs(nums,t+1);
            tmpans.pop_back();
            s[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        s.reset();
        dfs(nums,0);
        return ans;
    }
};
```
