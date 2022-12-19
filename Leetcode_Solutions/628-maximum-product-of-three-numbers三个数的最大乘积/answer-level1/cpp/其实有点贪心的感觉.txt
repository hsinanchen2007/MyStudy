### 解题思路
要注意边界情况：即全为负数时，所以初始值应该设置为nums[0] * nums[1] * nums[2]而不是0，最后还要和最小的两个值乘以最大的那个值的结果判断，因为这样也可能会出来一个更大的数字。

### 代码

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxx = nums[0] * nums[1] * nums[2];
        for(int i = nums.size() - 1 ; i >= 2 ; i--)
        {
            if(nums[i] < 0 && nums[i - 1] < 0 && nums[i - 2] < 0)
                break;
            maxx = max(nums[i] * nums[i - 1] * nums[i - 2], maxx);
        }
        return max(maxx, nums[0] * nums[1] * nums.back());
    }
};
```