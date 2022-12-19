```
const int N = 5e5 + 10;

int tmp[N];

class Solution {
public:
    int merge(vector<int> &nums, int l, int r) {
        if (l >= r) return 0;
        int mid = l + r >> 1;
        int ret = merge(nums, l, mid) + merge(nums, mid + 1, r);
        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
            else {
                tmp[k++] = nums[j++];
                ret += mid - i + 1;
            }
        }
        while (i <= mid) tmp[k++] = nums[i++];
        while (j <= r) tmp[k++] = nums[j++];
        for (int i = l, k = 0; i <= r; i++) nums[i] = tmp[k++];
        return ret;
    }

    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size() - 1);
    }
};
```
