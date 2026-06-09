### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] results = new int[2];
        int left = 0, right = nums.length - 1;
        
        while(left < right) {
            if(nums[left] + nums[right] == target) {
                results[0] = nums[left];
                results[1] = nums[right];
                return results;
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return results;
    }
}
```