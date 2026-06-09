### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<2) return 0;
        vector<int> ans;
        int res=0;
        for(int i=1;i<nums.size();i++)
        {
            ans.push_back(nums[i]-nums[i-1]);
        }
        sort(ans.begin(),ans.end());
        res=ans.back();
        return res;
    }
};
```