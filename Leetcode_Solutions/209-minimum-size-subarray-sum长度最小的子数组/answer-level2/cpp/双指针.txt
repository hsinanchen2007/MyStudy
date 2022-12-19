### 解题思路


### 代码

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0;
        int sum = 0;
        int minn = nums.size() + 1;
        while(j < nums.size())
        {
            if(sum < s)
                sum += nums[j++];
            else
            {
                minn = min(minn, j - i);
                sum -= nums[i++];
            }
        }
        while(sum >= s && i < nums.size())
        {
            minn = min(minn, j - i);
            sum -= nums[i++];
        }
        if(minn == nums.size() + 1)
            return 0;
        else
            return minn;
    }
};
```