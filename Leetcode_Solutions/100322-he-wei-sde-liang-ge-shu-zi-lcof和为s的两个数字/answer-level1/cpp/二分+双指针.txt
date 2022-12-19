看到大家都在直接用双指针，我注意到题目中给的是一个递增数组，所以想用二分来加速。
思路很简单，就是先用二分法找到第一个比target小的数，然后用双指针进行搜索。
很遗憾时间复杂度没降低 O(logn + n) = O(n)

```c++
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        r = l;
        l = 0;
        while (nums[l] + nums[r] != target)
        {
            if (nums[l] + nums[r] > target)
                r--;
            else
                l++;
        }

        vector<int> v{nums[l], nums[r]};
        return v;
    }
};
```
