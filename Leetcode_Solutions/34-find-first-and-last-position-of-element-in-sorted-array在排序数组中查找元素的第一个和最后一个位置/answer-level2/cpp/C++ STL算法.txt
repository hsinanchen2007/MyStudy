### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        auto left=find(nums.begin(),nums.end(),target);
        auto right=find(nums.rbegin(),nums.rend(),target);
        if(left==nums.end() && right==nums.rend()) return {-1,-1};
        else 
        {
            int i=int (left-nums.begin());
            int j=nums.size()-(right-nums.rbegin())-1;
            return {i,j};
        }
    }
};
```