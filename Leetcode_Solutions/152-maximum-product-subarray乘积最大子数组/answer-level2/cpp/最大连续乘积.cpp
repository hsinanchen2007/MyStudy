### 解题思路
此处撰写解题思路
因为必须是连续的数，所以需要考虑遇到正数和负数的情况，所以每次乘积时，不仅要记录当前最大值，也要记录当前最小值，因为可能最小值乘以一个负数变成最大。
获得数，可分为三种情况，max(当前最大值)，min(当前最小值)
Max应为(nums[i],max*nums[i],min*nums[i]中的最大值)
Min则为(nums[i],max*nums[i],min*nums[i]中的最小值)
### 代码

```cpp
#include<algorithm>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0];
        int Max = nums[0];
        int Min = nums[0];
        int p = Max;
        for(int i = 1; i < len; i++){
            int tmp = Max;
            Max = max(max(Max*nums[i],nums[i]),Min*nums[i]);
            Min = min(min(tmp*nums[i],nums[i]),Min*nums[i]);
            p = max(p,Max);
        }
        return p;                           
    }
};
```