```
class Solution {
    public int findPeakElement(int[] nums) {
        // 既然时间复杂度要求是O(logN)那意味着只能是二分查找的方式了
        int len = nums.length;
        if (len == 1) return 0;
        if (len == 2) return nums[0] > nums[1] ? 0 : 1; // 如果只是两个元素那找到最大的那个就可以了

        int left = 0, right = len - 1;
        while (right >= left){
            if(right == left) return right; // 剩一个了那就直接返回
            if (right - left == 1) return nums[left] > nums[right] ? left : right; // 剩两个比较大小即可
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid; // 如果刚好是峰顶的直接返回

            if (nums[mid] < nums[mid - 1]){ // 随便找一个升序的就好了
                right = mid - 1;
            }else if (nums[mid] < nums[mid + 1]){
                left = mid + 1;
            }
        }

        return -1;
    }
}
```
