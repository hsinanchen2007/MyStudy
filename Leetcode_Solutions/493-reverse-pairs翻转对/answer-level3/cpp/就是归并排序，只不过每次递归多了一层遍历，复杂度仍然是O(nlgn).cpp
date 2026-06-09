```
class Solution {
public:
    int reversePairs(vector<int> &nums) {
        return merge_sort(nums, 0, nums.size() - 1);
    }
private:
    int merge_sort(vector<int> &nums, int p, int q) {
        if (p >= q) return 0;
        int middle = (p + q) / 2;
        int lcount = merge_sort(nums, p, middle);
        int rcount = merge_sort(nums, middle + 1, q);
        int ncount = 0;
        for (int i = p, j = middle + 1; j <= q; ++j) {
            while (i <= middle && (long long)nums[i] <= 2 * (long long)nums[j]) i++;
            if (i > middle) break;
            ncount += middle - i + 1;
        }
        inplace_merge(nums.begin() + p, nums.begin() + middle + 1, nums.begin() + q + 1);
        return lcount + rcount + ncount;
    }
};
```
