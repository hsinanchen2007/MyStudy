### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<vector<int>> res;
        res.push_back(nums);
       if(nums.empty()||nums.size()==1)
           return res;
       int len = nums.size();
       backtrack(nums,res,len);
       return res;
    }
    bool IsReverse(vector<int>& nums,int len)
    {
        for(int i=0;i<len-1;i++)
        {
            if(nums[i]<nums[i+1])
            return false;
        }
        return true;
    }
    void backtrack(vector<int>& nums,vector<vector<int>>& res,int len)
    {
        if(IsReverse(nums,len))
        return ;
        else
        {
            int j = len-2;
            while(j>=00&&nums[j]>=nums[j+1])
            --j;
            int k = len-1;
            while(k>=0&&nums[k]<=nums[j])
            --k;
            swap(nums[j],nums[k]);
            j =j+1;
            k = len-1;
            while(j<k)
            {
                swap(nums[j],nums[k]);
                j++;
                k--;
            }
            res.push_back(nums);
            backtrack(nums,res,len);
        }
    }
};
```