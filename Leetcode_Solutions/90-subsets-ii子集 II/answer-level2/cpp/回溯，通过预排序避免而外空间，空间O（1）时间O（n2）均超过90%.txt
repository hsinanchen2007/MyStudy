这个只需要判别前一个是不是刚被访问过，如果是则进行剪枝：
```
class Solution {
public:
    int preVisit=INT_MIN;
    void generate(vector<vector<int>>& res,const vector<int>& nums,int start,vector<int>& pre)
    {
        res.push_back(pre);
        for(int i=start;i<nums.size();++i)
        {
            if(nums[i]==preVisit)
            {
                continue;
            }
            pre.push_back(nums[i]);
            generate(res,nums,i+1,pre);
            pre.pop_back();
            preVisit=nums[i];
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        generate(res,nums,0,tmp);
        return res;
    }
};
```
