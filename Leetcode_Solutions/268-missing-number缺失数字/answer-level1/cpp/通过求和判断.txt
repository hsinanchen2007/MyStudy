### 解题思路
求和相减判断

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for(int i=1;i<=nums.size();i++)
            sum+=i;
        for(int i=0;i<nums.size();i++)
            sum-=nums[i];
        return sum;
    }
};
```