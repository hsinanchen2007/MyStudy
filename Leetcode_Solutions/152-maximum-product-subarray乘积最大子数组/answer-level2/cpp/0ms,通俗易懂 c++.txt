### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int cur_max = nums[0];
        int cur_min = nums[0];
        int result = cur_max;
        for(int i=1;i<nums.size();i++)
        {
            int new_max = max(max(nums[i], cur_max*nums[i]), cur_min*nums[i]);
            int new_min = min(min(nums[i], cur_max*nums[i]), cur_min*nums[i]);
            cur_max = new_max;
            cur_min = new_min;
            if(cur_max>result)
                result = cur_max;
        }
        return result;
    }
};
```