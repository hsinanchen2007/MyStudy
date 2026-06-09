### 解题思路
沿用快排思路
找到分割点，根据分割点的index判断向左还是向右查找

### 代码

```cpp
class Solution {
public:
    int findIndex(vector<int>& nums, int l, int r) {
        int m = nums[l];
        int low = l;
        int high = r;
        while (l < r) {
            while (l < r && nums[r] >= m) {
                r--;
            }
            nums[l] = nums[r];
            while (l < r && nums[l] <= m) {
                l++;
            }     
            nums[r] = nums[l];  
        }
        nums[l] = m;
        return l;
    }
    void quickSortFindK(vector<int>& nums, int & k, int l, int r, int &target) {
        if (l > r) return;
        if (k == -1) return;
        if (l == r) {
            if (l == k) {
                target = nums[l];
                k = -1;
            }
            return;
        }
        int index = findIndex(nums, l, r);
        if (index == k) {
            target = nums[index];
            k = -1;
            return;
        }
        if (k > index) quickSortFindK(nums, k, index + 1, r, target);
        else quickSortFindK(nums, k, l, index - 1, target);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int target;
        int m = nums.size() - k;
        quickSortFindK(nums, m, 0, nums.size()-1, target);
        return target;
    }
};
```