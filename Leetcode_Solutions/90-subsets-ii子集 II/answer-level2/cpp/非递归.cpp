```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        result.push_back(vector<int>{});
        int x=0;
        for(int i=0;i<nums.size();++i)
        {
            if(i!=0&&nums[i]==nums[i-1])
            {
                int len=result.size();
                for(int y=x;y>=1;--y)
                {
                    vector<int> temp=result[len-y];
                    temp.push_back(nums[i]);
                    result.push_back(temp);
                }
            }
            else
            {
                int len=result.size();
                x=len;
                for(int j=0;j<len;++j)
                {
                    vector<int> temp=result[j];
                    temp.push_back(nums[i]);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};
```
