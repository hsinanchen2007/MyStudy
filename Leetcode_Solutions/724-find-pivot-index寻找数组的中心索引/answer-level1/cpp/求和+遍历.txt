Python3
```
from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        sum_ = sum(nums)
        tmp = 0
        for k, num in enumerate(nums):
            if k > 0:
                tmp += nums[k-1]
            if 2*tmp == sum_ - num:
                return k
        return -1
```

C++
```
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int tmp = 0;
        for (int k = 0; k < nums.size(); ++k)
        {
            if (k > 0)
            {
                tmp += nums[k-1];
            }
            if (2*tmp == sum-nums[k])
            {
                return k;
            }
        }
        return -1;
    }
};
```

时间复杂度：O(n)
空间复杂度：O(1)
