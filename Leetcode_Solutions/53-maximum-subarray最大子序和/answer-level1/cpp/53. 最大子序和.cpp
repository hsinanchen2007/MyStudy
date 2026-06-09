动态规划和分治法待补充

贪心解法

代码：
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, tmp = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(tmp <= 0) tmp = nums[i];
            else tmp += nums[i];
            if(tmp > res) res = tmp;
        }
        return res;
    }
};
```
