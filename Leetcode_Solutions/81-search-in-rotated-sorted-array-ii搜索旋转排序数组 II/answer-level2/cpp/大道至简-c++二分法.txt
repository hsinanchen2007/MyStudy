```
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            // 去重
            while (low < high && nums[low] == nums[low + 1]) {
                low++;
            }
            while (low < high && nums[high] == nums[high - 1]) {
                high--;
            }
            // 以下代码与题目33题一致，无修改地方
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return true;
            }
            // 把数组大致分为两组，一组为左侧未旋转有序数组，一组为右侧旋转有序数组
            // 如[3 4 5 1 2]， [3，4，5]称为左侧，[1，2]称为右侧

            // 0~mid有序，向后规约条件
            // nums[mid] >= nums[0] 表示0~mid有序
            // target > nums[mid] 表示target位于左侧且大于nums[mid],向后规约
            // target < nums[0] 表示target位于右侧，向后规约
            if (nums[mid] >= nums[0] && (target > nums[mid] || target < nums[0])) {
                low = mid + 1;
            } else if (nums[mid] < nums[0] && target > nums[mid] && target < nums[0]) { // 0~mid无序(即包含翻转点)，向后规约条件
                // nums[mid] < nums[0] 表示nums[mid]位于右侧
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
}
};
```
