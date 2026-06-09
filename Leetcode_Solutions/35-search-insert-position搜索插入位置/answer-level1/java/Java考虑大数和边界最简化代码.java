```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int p = 0;
        int q = nums.length;
        while(p < q){
            int mid = p + (q - p) / 2;
            if(nums[mid] < target){
                p = mid + 1;
            } else {
                q = mid;
            }
        }
        return p;
    }
}
```
