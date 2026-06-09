### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2,0);
        if(nums.size()<2) return res;
        int i=0,j=nums.size()-1;
        while(nums[i]+nums[j]!=target && i<j)
        {
            if(nums[i]+nums[j]<target) ++i;
            else --j;
        }
        res[0]=nums[i];
        res[1]=nums[j];
        return res;

    }
};
```