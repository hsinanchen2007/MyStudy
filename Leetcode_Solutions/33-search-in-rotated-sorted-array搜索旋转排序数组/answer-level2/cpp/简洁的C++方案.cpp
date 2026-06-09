该题的循环不变量是：**在任一次迭代中，其中一半元素满足升序，另一半不是**。
当`target`不在升序段时就可以排除，去剩下一半去查找。详细看注释。
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            
            if (nums[l] < nums[m]) { // numbers in [l..m] are in ascending order
                if (nums[m] < target || target < nums[l]) l = m; // target does not exist in [l..m]
                else r = m;
            } else if (nums[m] < nums[r]) { // numbers in [m..r] are in ascending order
                if (target < nums[m] || target > nums[r]) r = m; // target does not exist in [m..r]
                else l = m;
            }
        }// l + 1 == r
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;
        return -1;
    }
};
```
