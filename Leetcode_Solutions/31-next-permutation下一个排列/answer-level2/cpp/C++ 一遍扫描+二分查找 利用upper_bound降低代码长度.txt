```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() > 1) {
            int i;
            for (i = nums.size() - 1; i > 0 && nums[i - 1] >= nums[i]; i--);

            reverse(nums.begin() + i, nums.end());
            if (i-- != 0) {
                auto it = upper_bound(nums.begin() + i, nums.end(), nums[i]);
                swap(nums[i], *it);

                //或者手撸二分查找
                //int left = i--;
                //int right = nums.size() - 1;
                //while (left <= right) {
                //	int mid = (left + right) / 2;
                //	if (nums[mid] > nums[i]) {
                //		right = mid - 1;
                //	}
                //	else {
                //		left = mid + 1;
                //	}
                //}
                //swap(nums[i], left);
            }
        }
    }
};
```

