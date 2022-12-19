对数组所有元素求和，已知0到n和为(n+1)*n/2，差值就是缺的数

代码：
```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for(int i = 0 ; i < len ; i++)
            sum += nums[i];
        return (((len + 1) * len) >> 1) - sum;
    }
};
```
