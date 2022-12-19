**排序数组二分查找第一次出现的数**
```
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<int> tmp;
        for (auto &i : nums) {
            tmp.push_back(i);
        }
        sort(tmp.begin(), tmp.end());
        vector<int> res;
        for (auto &i : nums) {
            int index = findFirst(tmp, i);
            res.push_back(index);
        }
        return res;
    }

    int findFirst(vector<int> &nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] == k && (m - 1 < 0 || nums[m - 1] != k)) {
                return m;
            } else if (nums[m] >= k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};
```
