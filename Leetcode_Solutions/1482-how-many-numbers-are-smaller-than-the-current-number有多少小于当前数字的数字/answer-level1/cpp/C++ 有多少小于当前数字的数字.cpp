### 解题思路
采用最暴力的做法，对当前的数i双向遍历即可
时间复杂度O(N2)

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans((int)nums.size(), 0);
        for(int i=0;i<=n-1;i++)
        {
            if(i!=0)
            {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                {
                    ans[i]++;
                }
            }
            }
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]<nums[i])
                {
                    ans[i]++;
                }
            }
        }
        return ans;

    }
};
```