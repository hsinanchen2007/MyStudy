```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitSum = 0;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            bitSum = 0;//每一轮进行归零
            int bit = 1 << i;//统计当前位一共的和为多少
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] & bit)) {
                     bitSum += 1;
                }
            }
            ans = ans << 1;//循环32次，但是最多左移31位，且第一次是不用移
            ans += bitSum % 3;
        }
        return ans;
    }
};
```
