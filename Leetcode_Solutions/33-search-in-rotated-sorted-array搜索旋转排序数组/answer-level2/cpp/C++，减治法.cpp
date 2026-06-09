### 解题思路
先将比较容易想到的情况写在 if 里，那么这种情况的反面就可以直接扔到 else 里，便于逻辑上的思考。

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;   // 特判

        int left = 0, mid, right = nums.size() - 1;

        while(left < right) {
            // 中位数采用下取整方式获得，上下取整的不同将影响后面判断 target 区间时的边界收缩行为
             mid = left + (right - left) / 2;

            // 如果中间元素严格小于右边界，说明区间 [mid, right] 一定有序，
            // 此时 target 要么在有序区间 [mid, right] 内，
            // 要么在无序区间 [left, mid - 1] 内
            if(nums[mid] < nums[right]) {
                if(nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid;
            }
            
            // 如果中间元素严格大于右边界，说明区间 [left, mid] 一定有序，
            // 此时 target 要么在有序区间 [left, mid] 内，
            // 要么在无序区间 [mid + 1, right] 内，

            // 因为 mid 下取整，且数组中不含重复元素，所以 nums[mid] 和 nums[right] 只存在大小关系、不可能相等，
            // 故下面这个 else 其实只有 nums[mid] > nums[right] 这一种情况，
            // 这是对 else if(nums[mid] > nums[right]) 的简写
            else {
                // 为了和上一个 if 有同样的边界收缩行为，if 判断的条件要适当改成如下
                if(nums[left] <= target && target <= nums[mid]) right = mid;
                else left = mid + 1;
            }


            // 下面是中位数 mid 采用上取整时的边界收缩行为示例
            // mid = left + (right - left + 1) / 2;

            // // 如果中间元素严格小于右边界，说明区间 [mid, right] 一定有序，
            // // 此时 target 要么在有序区间 [mid, right] 内，
            // // 要么在无序区间 [left, mid - 1] 内
            // if(nums[mid] < nums[right]) {
            //     if(nums[mid] <= target && target <= nums[right]) left = mid;
            //     else right = mid - 1;
            // }
            
            // // 如果中间元素严格大于右边界，说明区间 [left, mid] 一定有序，
            // // 此时 target 要么在有序区间 [left, mid] 内，
            // // 要么在无序区间 [mid + 1, right] 内，
            // // 这时为了和上一个 if 有同样的边界收缩行为，我们故意认为 [left, mid - 1] 有序，[mid, right] 无序
            // else {
            //     if(nums[left] <= target && target <= nums[mid - 1]) right = mid - 1;
            //     else left = mid;
            // }
        }

        if (nums[left] == target) return left;
        return -1;
    }
};
```