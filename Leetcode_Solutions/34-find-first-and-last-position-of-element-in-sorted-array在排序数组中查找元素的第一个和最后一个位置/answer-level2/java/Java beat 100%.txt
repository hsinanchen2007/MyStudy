```
public class Solution {
    private int minLeft, maxRight;
    private int binarySearch(int[] nums, int low, int high, int target) {
        int mid;
        while (low <= high) {
            mid = (low+high)/2;
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

    private void result(int[] nums,int low, int high, int target) {
        if (low > high || target > nums[high] || target < nums[low]) return ;
        int i = binarySearch(nums, low, high, target);
        if (i != -1) {
            minLeft = Math.min(minLeft, i);
            maxRight = Math.max(maxRight, i);
            result(nums, low, i-1, target);
            result(nums, i+1, high, target);
        }
    }

    // 100% 0ms(中文)  100% 0ms(英文)
    public int[] searchRange(int[] nums, int target) {
        if (nums.length == 0) return new int[]{-1, -1};
        minLeft = nums.length;
        maxRight = -1;
        result(nums, 0, nums.length-1, target);
        return new int[] {minLeft==nums.length ? -1 : minLeft, maxRight};
    }

    public static void main(String[] args) {
        int[] nums = {1};
        int[] ints = new Solution().searchRange(nums, 1);
        System.out.println("ints = " + ints[0]+","+ints[1]);
    }
}
```
