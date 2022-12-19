### 解题思路
1.数组长度为0，直接返回结果0
2.数组长度为1，返回结果nums[0]
3.数组长度为3，结果可能是nums[0]+nums[2]或者nums[1]
4.其他长度，建立辅助数组sum[len]。sum[i]为包含预约nums[i]的前i+1个预约的最大和，则sum[i]有两种可能，即sum[i-1]+nums[i] or sum[i-2]+nums[i]
5.最大预约要么是sum[i]要么是sum[i-1]，返回大的即可

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        else if(len == 1) return nums[0];
        else if(len == 2) return (nums[0] > nums[1]) ? nums[0] : nums[1];
        else if(len == 3) return max(nums[0] + nums[2], nums[1]);
        int sum[len];
        for(int i = 0; i < len; i++) sum[i] = 0;
        sum[0] = nums[0];
        sum[1] = nums[1];
        sum[2] = max(nums[0] + nums[2], nums[1]);
        for(int i = 3; i < len; i++){
            sum[i] = max(nums[i] + sum[i-3], sum[i-2] + nums[i]);
        }
        return (sum[len-1] > sum[len-2]) ? sum[len-1] : sum[len-2];
    }
};
```