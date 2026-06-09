### 解题思路

### 代码

```cpp
class Solution 
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> res;
        if(nums.empty()) return res;

        sort(nums.begin(),nums.end());
        res.push_back(nums);
        auto Next=next(nums);

        while(!Next.empty())
            res.push_back(Next),Next=next(Next);

        return res;
    }

    vector<int> next(vector<int> nums) 
    {
        for(int i=nums.size()-2;i>=0;i--)
        {
            int temp=1<<10,pos=i,find=0;

            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[i] && nums[j]<temp)
                {
                    pos=j;
                    temp=nums[j];
                    find=1;
                }
            }

            if(find)
            {
                swap(nums[pos],nums[i]);
                sort(nums.begin()+i+1,nums.end());
                return nums;
            }
        }

        return vector<int>();
    }
};
```