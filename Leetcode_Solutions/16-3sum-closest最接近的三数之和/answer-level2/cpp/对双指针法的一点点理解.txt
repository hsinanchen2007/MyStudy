### 解题思路
做了几道类似的题目以后就可以想到使用双指针法解决此题。但是这道题让我重新理解了双指针法的思想：实际就是贪心，因为是求有一个最优解，不论是相等还是差值最小本质上都是在求最优解，那么每次移动指针的时候，只有一个方向是可能更优的，一定要注意是可能，另一个方向肯定比当前更差，一定要注意是肯定。所以这道题的最优解必定是在双指针法移动的路径上。

### 代码

```cpp
#include <algorithm>
#include <cmath>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        int result;
        int distance = 0x7fffffff;

        for (int i = 0; i < length - 2; i++)
        {
            int begin = i + 1;
            int end = length - 1;
            int new_target = target - nums[i];
            while (begin < end)
            {
                if (nums[begin] + nums[end] < new_target)
                {
                    if (abs(nums[begin] + nums[end] - new_target) < distance)
                    {
                        distance = abs(nums[begin] + nums[end] - new_target);
                        result = nums[i] + nums[begin] + nums[end];
                    }
                    begin++;
                }
                else if (nums[begin] + nums[end] > new_target)
                {
                    if (abs(nums[begin] + nums[end] - new_target) < distance)
                    {
                        distance = abs(nums[begin] + nums[end] - new_target);
                        result = nums[i] + nums[begin] + nums[end];
                    }
                    end--;
                }
                else
                {
                    return target;
                }
            }
        }

        return result;
    }
};
```