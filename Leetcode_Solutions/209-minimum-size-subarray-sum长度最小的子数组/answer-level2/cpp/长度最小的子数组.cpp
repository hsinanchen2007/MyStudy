### 算法分析
1. 假设n = nums.size(), left = 0, sum = 0, len = INT_MAX
2. 遍历nums, i = 0 : n - 1
3. sum += nums[i]
   while sum >= s do
        len = min(len, i - left + 1)
        sum -= nums[left++]
4. return len != INT_MAX ? len : 0
### 复杂度分析
+ 时间复杂度：O(n)，n为nums长度
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int len = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            while (sum >= s)
            {
                len = min(len, i - left + 1);
                sum -= nums[left++];
            }
        }

        return len != INT_MAX ? len : 0;
    }
};