```
class Solution {
    public int search(int[] nums, int target) {
        if (nums.length == 0) return -1;
        // 先找出最小值的位置
        int l = 0;
        int r = nums.length - 1;
        int n = nums.length;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] <= nums[n - 1]) r = mid;
            else l = mid + 1;
        }
        int minIndex = r;
        
        // 根据target的大小判断是在前后哪一段中，确定位置后进行搜索
        if (target > nums[n - 1]) {
            l = 0;
            r = minIndex - 1;
        } else {
            l = minIndex;
            r = n - 1;
        }
        while (l < r) {
            int m = l + r >> 1;
            if (nums[m] >= target) r = m;
            else l = m + 1;
        }
        
        if (nums[l] != target) return -1;
        return l;
    }
}
```
