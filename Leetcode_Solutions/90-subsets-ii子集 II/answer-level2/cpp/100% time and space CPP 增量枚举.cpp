### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:

    void subcore(vector<vector<int>>& fin,vector<int>& temp,vector<int>& nums,int cur)
    {
        fin.push_back(temp);

        for(int i=cur;i<nums.size();i++)
        {
            if(i>cur && nums[i-1]==nums[i])
                continue;
            
            temp.push_back(nums[i]);
            subcore(fin,temp,nums,i+1);
            temp.pop_back();
        }

    }



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> fin;
        vector<int> temp;
        
        subcore(fin,temp,nums,0);
        return fin;
    }
};
```