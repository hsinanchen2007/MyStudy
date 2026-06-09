```cpp
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo >> 1);
        if (target == nums[mid] 
                || (nums[mid] < nums.front() || target < nums[mid]) && nums.front() <= target
                || target < nums[mid] && nums[mid] < nums.front()) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return nums.empty() ? -1 : (nums[lo] == target ? lo : -1);
}
```
