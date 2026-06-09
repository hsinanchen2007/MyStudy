```
class Solution {
    // 思路：不用找出旋转点。直接使用二分法，每次二分一定有一个半区是有序的，这半区无果再去另外一个半区查找即可。
    public int search(int[] nums, int target) {
        int res = -1;
        if(nums.length == 0) return res;
        return binarySort(nums, 0, nums.length - 1, target);
    }
    
    private int binarySort(int[] nums, int left, int right, int target) {
        if(right == left) {
            if(nums[left] == target) {
                return left;
            } else {
                return -1;
            }
        }
        int mid = (right + left) / 2;
        if(nums[left] < nums[mid]) { // 左半区有序
            if(target <= nums[mid] && target >= nums[left]) {
                return binarySort(nums, left, mid, target);
            } else {
                return binarySort(nums, mid + 1, right, target);
            }
        } else { // 右半区有序
            if(target <= nums[right] && target >= nums[mid + 1]) {
                return binarySort(nums, mid + 1, right, target);
            } else {
                return binarySort(nums, left, mid, target);
            }
        }
    }
}
```
