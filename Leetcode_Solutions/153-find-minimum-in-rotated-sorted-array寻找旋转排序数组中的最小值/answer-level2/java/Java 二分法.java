思路和官方题解很像，如果想要找个代码看看可以瞧一瞧
```
class Solution {
    public int findMin(int[] nums) {
        //if (nums.length == 0) return null;
        int left = 0, right = nums.length - 1;
        while(left < right) {
            int mid = (int)Math.ceil((left + right)/ 2.0);
            if (nums[mid] < nums[mid - 1]) return nums[mid];
            if (nums[left] > nums[right]) {
                if (nums[mid] > nums[left]) left = mid + 1;
                else right = mid - 1; 
            }
            else {
                if (nums[mid] < nums[left]) left = mid + 1;
                else right = mid - 1; 
            }                     
        }
        return nums[left];
    }
}
```
