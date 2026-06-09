```
class Solution {
    public int search(int[] nums, int target) {
        return partition(nums, target, 0, nums.length-1);
    }

    // 思路，先是判断哪半边是有序的，对有序的半边进行二分查找，对无序的半边继续进行切分，重复这个过程。
    public int partition(int[] nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = (left + right + 1) >>> 1;
        if (nums[mid] > nums[left] && nums[mid] > nums[right]) {    // 如果轴点在右半边，即左边有序
            int temp = binarySearch(nums, target, left, mid);       
            if (temp != -1) return temp; 
            return partition(nums, target, mid+1, right);
        } else {                                                    // 如果轴点在左半边，即右边有序
            int temp = binarySearch(nums, target, mid, right);      
            if (temp != -1) return temp;
            return partition(nums, target, left, mid-1);
        }
    }

    // 二分查找
    public int binarySearch(int[] nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        if (target < nums[left] || target > nums[right]) {
            return -1;
        }
        int mid = (left + right + 1) >>> 1;
        if (nums[mid] < target) {
            return binarySearch(nums, target, mid+1, right);
        } else if (nums[mid] > target) {
            return binarySearch(nums, target, left, mid-1);
        } else {
            return mid;
        }
    }
}
```
