由于乘法的特殊性，所以string上每一位的乘积最大值（不论正负），都只与前一个值能达到的最大值（当前数字为正）和最小值（当前数位为负）有关系。所以，只存储上一位的最大和最小可能乘积，然后计算并储存，计算后比较该数位最大值与之前所有数位的最大可能出现的乘积，记录。一次历遍，时间O(n)， 空间O(1)。

```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i, ret, pos, neg, temp;
        pos = nums[0];
        neg = nums[0];
        ret = nums[0];
        for(i = 1; i < nums.size(); i++){
            temp = pos;
            pos = max(nums[i], max(pos * nums[i], neg * nums[i]));
            neg = min(nums[i], min(temp * nums[i], neg * nums[i]));
            ret = max(pos, ret);
        }
        return ret;
    }
};
```