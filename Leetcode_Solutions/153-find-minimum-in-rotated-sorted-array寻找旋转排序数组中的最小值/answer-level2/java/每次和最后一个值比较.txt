### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        if(nums == null ||nums.length == 0) {
            return 0;
        }
        
        int n = nums.length;        
        int start = 0, end = n - 1;
        int target = nums[n - 1];
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] > target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        return Math.min(nums[start], nums[end]);
    }
}
```