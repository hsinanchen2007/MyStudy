### 解题思路

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums[0];
        for(int i = 0;i<=end;i++)
        {
            end = max(end,nums[i]+i);
            if (end>=nums.size()-1) return true;
        }
        return false;
        
    }
    
};
```