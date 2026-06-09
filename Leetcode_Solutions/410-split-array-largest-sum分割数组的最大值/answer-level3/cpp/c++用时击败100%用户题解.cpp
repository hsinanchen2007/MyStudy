执行用时 : 0 ms , 在所有 C++ 提交中击败了100.00%的用户
内存消耗 : 8.4 MB, 在所有 C++ 提交中击败了98.91%的用户
```
class Solution {
public:
    bool match(vector<int>& nums, int m, int s) {
        int left = 0;
        int count = 0;
        while (left < nums.size()) {
            if (nums[left] > s)
                return false;
            int s1 = s;
            while (left < nums.size() && s1 - nums[left] >= 0) {
                s1 -= nums[left];
                ++left;
            }
            ++count;
            if (count > m)
                return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        // 选择一个满足条件的步长，并先给出一个上界
        int step = nums.size() / m;
        if (nums.size() % m != 0)
            ++step;
        for (int i = 0; i < nums.size(); i += step) {
            int s = 0;
            for (int j = 0; j < step && i + j < nums.size(); ++j) {
                s += nums[i + j];
            }
            if (s > sum) sum = s;
        }
        // 二分查找得到最终解
        int left = 0;
        int right = sum;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (match(nums, m, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
```