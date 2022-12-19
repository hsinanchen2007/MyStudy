### 解题思路
窗口滑动

### 代码

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int res = INT_MAX;
        int left = 0, right = 0;
        int sum = 0;
        int length = nums.size();
        int curlength = 0;
        while(right < length)
        {
            if(sum + nums[right] < s)
            {
                sum += nums[right];
                ++right;
            }
            else
            {
               curlength = right + 1 - left;
               res = res > curlength ? curlength :res;
               sum -= nums[left];
               ++left;
            }
        }
        return res == INT_MAX? 0:res;
    }
};


```