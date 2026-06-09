### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        while(nums.size()==0)return 0;
        int ans=nums[0];
        vector<int> temp={nums[0]};
        for(int i=1;i<nums.size();i++)
        {
            if(temp[i-1]>0) temp.push_back(nums[i]+temp[i-1]);
            else temp.push_back(nums[i]);
            if(temp[i]>ans) ans=temp[i];

        }
        return ans;
    }
};
```