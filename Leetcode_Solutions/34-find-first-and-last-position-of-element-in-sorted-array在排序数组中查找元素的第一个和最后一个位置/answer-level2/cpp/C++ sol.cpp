### 解题思路
二分法，需要注意的是 l=0, r = nums.size()，这意味着遍历区间是 [l, r)，因此在缩小范围时，总是 [l+1, mid)。

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        if (r==0) return {-1,-1};

        // 获得左侧第一个元素[l,r) -> [l, mid), [mid+1, r)
        while (l < r) {
            int mid = l+(r-l)/2; // 避免越界的常用手法
            if (nums[mid] == target) {
                r = mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid;
            }
        }

        int lf = -1;
        if (l == nums.size()) lf = -1;
        else lf = nums[l]==target ? l : -1;

        // 获得右侧最后一个元素[l, r) -> [l, mid), [mid+1,r)
        l = 0, r = nums.size();
        while (l < r) {
            int mid = l+(r-l)/2; // 避免越界
            if (nums[mid] == target) {
                l = mid+1;
            } else if (nums[mid] < target) {
                l = mid+1;
            } else if (nums[mid] > target) {
                r = mid;
            }
        }

        int rf = -1;
        if (l == 0) rf = -1;
        else rf = nums[l-1]==target ? l-1 : -1;
        
        return {lf, rf};
    }
};
};
```