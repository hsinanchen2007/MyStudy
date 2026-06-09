### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=i)return i;
        return nums.size();
    }
};
```