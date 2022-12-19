### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < 2; i++)
        {
            int d1 = 0;
            int d2 = 0;
            int d3 = 0;
            for(int j = i; j < n - 1 + i; j++)
            {
                d3 = max(d2, d1 + nums[j]);
                d1 = d2;
                d2 = d3;
            }
            ans = max(ans, d3);
        }
        return ans;

    }
};
```