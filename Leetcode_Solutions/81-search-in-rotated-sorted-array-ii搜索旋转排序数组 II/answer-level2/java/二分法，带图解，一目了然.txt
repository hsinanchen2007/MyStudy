对于[33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/)，数组中元素的排列肯定如下图所示(横坐标为index，纵坐标为值)：
        
```
  |             *
  |           * |
  |         *   |
  |       *     |
  |     1       |
  |             |       2
  |             |    *
  |             |  *
  |             *            
  |—————————————————————————

  元素2肯定比元素1小
```
对于本题，只要把首尾相同的元素去掉，就变成了[33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/)。
```
class Solution {
    public boolean search(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return false;
        }
        if (nums.length == 1) {
            return nums[0] == target;
        }
        int pre = 0;
        int post = nums.length - 1;
        //去除最前面和末尾相同的元素
        while (pre < post && nums[pre] == nums[post]) {
            pre++;
        }
        int first = pre;
        while (pre < post) {
            int mid = (pre + post) >>> 1;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] >= nums[first]) { //说明前半部分有序
                if (target < nums[mid] && target >= nums[pre]) {
                    post = mid;
                } else {
                    pre = mid + 1;
                }
            } else if (nums[mid] <= nums[nums.length - 1]) {//说明后半部分有序
                if (target > nums[mid] && target <= nums[post]) {
                    pre = mid + 1;
                } else {
                    post = mid;
                }
            }
        }
        return nums[pre] == target;
    }
}
```
