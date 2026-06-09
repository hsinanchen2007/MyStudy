### 解题思路
动态规划法
### 代码
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Max=INT_MIN,sum=0;
        for (int i=0;i<nums.size();i++){
            sum=max(sum+nums[i],nums[i]);
            Max=max(sum,Max);
        }
        return Max>sum?Max:sum;
    }
};
```