### 解题思路
原理：当第一个数大于第二个数时，第一数可选的子序列范围大于第二个数，即第一个数为必选数；
若第一个数小于第二数时，第一个数和第一个数的选择范围不统一，需要归一，即将第一个数加到第三个数上，
从第二数开始进行DP。
操作：
1、如果第一个数大于第二个数，则nums[i] + dp(i+2, i+3,...,i+n);
2、如果第一个数小于第二个数，则将第一个数加到第三个数上，dp(i+1,i+2,...,i+n);

### 代码

```cpp
class Solution {
public:
int massage(vector<int>& nums, int i){
    if(i >= nums.size())
        return 0;

    if(i + 1 < nums.size()){
        if(nums[i] > nums[i + 1])
            return nums[i] + massage(nums, i + 2);
        else if(i + 2 < nums.size()){
            nums[i + 2] += nums[i];
            return massage(nums, i + 1);
        } else
            return nums[i + 1];
    } else
        return nums[i];
}

int massage(vector<int>& nums) {
    return massage(nums, 0);
}
};
```