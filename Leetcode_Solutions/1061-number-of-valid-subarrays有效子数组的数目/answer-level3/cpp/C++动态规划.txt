用一个数组保存分别以每个元素开头的子数组个数，从后往前进行动态规划

动态规划时，先查找该元素后面1个元素是否不比他大，如果不比其大，则跳到该元素最后面的位置再判断。

```c++
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp(length, 1);
        int ans = 1;
        for(int i = length-2;i >= 0;--i){
            int j = i + 1;
            while(j < length && nums[i] <= nums[j]){
                j += dp[j];
            }
            dp[i] = j - i;
            // cout << "dp[" << i << "]=" << dp[i] << endl;
            ans += dp[i];
        }
        return ans;
    }
};
```
