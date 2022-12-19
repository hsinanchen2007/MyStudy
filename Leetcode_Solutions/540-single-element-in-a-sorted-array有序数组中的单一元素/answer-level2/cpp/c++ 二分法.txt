梳理一下思路：
O(logn)时间复杂度，O(1)空间复杂度 => 二分法。

数组只有一个出现一个的数字，其余成对出现 => 数组总元素个数为奇数。
核心：答案值只会出现在奇数个元素的数组中。

二分搜索时，low为数组范围左侧下标，high为右侧下标，
mid = (low + high) / 2，mid有两种情况，下标为奇数或者偶数：
下标为奇数时：
    数组被这个nums[mid]划分为2部分：奇数个数 + nums[mid] + 奇数个数，
    有两种情况：
    1.nums[mid] == nums[mid + 1]，此时数组情况为：
        奇数个数 + nums[mid]、nums[mid + 1] + 偶数个数，因此答案只会出现在左边的奇数个数，
    故令high = mid
    2.nums[mid] != nums[mid + 1], 那么右边的奇数个数只能是包含单个数的，因此令low = mid + 1。
下标为偶数时：
    数组同样被划分为2部分：偶数个数 + nums[mid] + 偶数个数，
    同样也有两种情况：
    1.nums[mid] == nums[mid + 1]，此时数组情况为：
        偶数个数 + nums[mid]、nums[mid + 1] + 奇数个数，因此答案只会出现在右边的奇数个数，
    故令low = mid + 2;
    2.nums[mid] != nums[mid + 1], 那么右边的偶数个数是不可能包含答案值的，令high = mid。

因为循环体控制条件为low < high,因此不会出现mid == high的情况，high的最大值为nums.size() - 1,即
mid总是小于nums.size() - 1, 因此nums[mid + 1]不会产生越界的情况。
```
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = ((r - l) >> 1) + l;
            if(mid % 2) {
                if(nums[mid] == nums[mid + 1]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else {
                if(nums[mid] == nums[mid + 1]) {
                    l = mid + 2;
                } else {
                    r = mid;
                }
            }
        }
        return nums[l];
    }
};
```
