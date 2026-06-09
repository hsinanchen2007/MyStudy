### 解题思路


### 代码

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        if(n == 0)
            return 0;
        if(nums[0] >= s)
            return 1;
        int sum[n];
        sum[0] = nums[0];
        for(int i = 1 ; i < n ; ++i)
            sum[i] = sum[i - 1] + nums[i];
        int minn = n + 1;
        int left = 0, right = n - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(sum[mid] >= s)
                right = mid;
            else
                left = mid + 1;
        }
        if(sum[left]>= s)
            minn = min(minn, left + 1);
        for(int i = 1 ; i < n ; ++i)
        {
            int left = i, right = n - 1;
            while(left < right)
            {
                int mid = left + (right - left) / 2;
                if(sum[mid] - sum[i - 1] >= s)
                    right = mid;
                else
                    left = mid + 1;
            }
            if(sum[left] - sum[i - 1] >= s)
                minn = min(minn, left - i + 1);
        }
        if(minn == nums.size() + 1)
            return 0;
        else
            return minn;
    }
};
```