### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        if(nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];
        int left = 0, right = nums.length - 1;
        while(left < right){
            if(nums[left] < nums[right]){
                return nums[left];
            }
            int mid = (left + right) / 2;
            // 3 4 5 0 1
            // 3 4 5 6 8
            if(nums[mid] > nums[left]){
                if(nums[mid] > nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid;
                }
            }else{
                left++;
            }
        }
        return nums[left];
    }
}
```