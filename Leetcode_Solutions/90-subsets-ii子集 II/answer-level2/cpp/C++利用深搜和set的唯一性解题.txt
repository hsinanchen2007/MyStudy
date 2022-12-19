先排序真个数组，然后枚举每一个子集。在枚举的过程中如果set中查不到当前子集，则将当前子集插入到set中，如果查得到当前子集，则不保存当前子集，将其啊略过。
代码如下：
```
set<vector<int>> myset;
    vector<vector<int>> ans;
    vector<int> tmpans;

    void dfs(vector<int>& nums,int s)
    {
        if(s==nums.size())
        {
            if(myset.count(tmpans)>0)
                return;
            myset.insert(tmpans);
            ans.push_back(tmpans);
            return;
        }
        dfs(nums,s+1);

        tmpans.push_back(nums[s]);
        dfs(nums,s+1);
        tmpans.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len=nums.size();
        if(len==0)
            return{{}};
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return ans;
    }
```
