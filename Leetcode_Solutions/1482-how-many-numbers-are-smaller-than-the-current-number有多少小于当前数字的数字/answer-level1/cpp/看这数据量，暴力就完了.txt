

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int i, j, count, k = 0;
        vector<int> ans(nums.size());
        for(i = 0; i < nums.size(); ++i)
        {
            count = 0;
            for(j = 0; j < nums.size(); ++j)
            {
                if(nums[j] < nums[i])
                    count++;
            }
            ans[k++] = count;
        }
        return ans;
    }
};
```