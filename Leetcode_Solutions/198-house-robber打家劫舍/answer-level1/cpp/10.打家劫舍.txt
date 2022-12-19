### 解题思路
关键是找转移方程，其实很简单但还是看了题解，还有特殊情况考虑周全一点啊啊啊啊不要总犯小错误了一遍过好不好

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> money(nums.size());
        if(nums.size()==1) return nums[0];
        money[0]=nums[0];
        money[1]=nums[0]>nums[1]?nums[0]:nums[1];  
        int i;
        for(i=2;i<nums.size();i++){
            money[i]=max(money[i-1],nums[i]+money[i-2]);
        }
        return money[i-1];
    }
};
```