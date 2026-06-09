### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i<nums.size();)
        {
            res+=nums[i];
            i+=2;    
        }
        return res;
    }
};

```