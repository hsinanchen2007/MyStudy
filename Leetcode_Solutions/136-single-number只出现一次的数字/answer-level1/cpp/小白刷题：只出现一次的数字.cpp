两个相同的数异或结果为0，而0与任何数异或结果为它本身，所以数组所有元素异或的结果，就是只出现一次的元素

代码：
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int ans = nums[0];
        for (int i = 1; i < len; i++)
            ans = ans ^ nums[i];
        return ans;
    }
};
```
