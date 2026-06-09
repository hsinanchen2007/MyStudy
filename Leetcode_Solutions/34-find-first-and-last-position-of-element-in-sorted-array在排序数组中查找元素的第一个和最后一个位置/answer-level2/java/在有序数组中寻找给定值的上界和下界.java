### 解题思路
首先使用二分法获取left和right，然后分别向左右延申找到上下界

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums.length < 1){
            return new int[]{-1,-1};
        }
        int left = 0;
        int right = nums.length - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                left = right = mid;
                break;
            }
            if(target > nums[mid]){
                left = mid + 1;
            }else{
                right = mid;
            }
            if(nums[left] == nums[right] && nums[left] == target) break;
        }
        if(nums[left] != target){
            return new int[]{-1,-1};
        }
        do {
            if(++right >= nums.length) break;
        } while(nums[right] == target);

        do {
            if(--left < 0) break;
        } while(nums[left] == target);

        return new int[]{++left, --right};
    }
}
```