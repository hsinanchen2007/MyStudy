
要点有二：
1） right一定要设置为nums.size(),而不是-1
2） 由于插入数字可能与原数组中数字相同，比较的时候要用 nums[mid] >= target
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left =0, right= nums.size();
        while (left < right)
        {
            int mid = left + (right - left)/2;

            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
```
