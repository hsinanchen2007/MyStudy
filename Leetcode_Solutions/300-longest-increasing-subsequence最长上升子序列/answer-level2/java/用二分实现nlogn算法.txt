### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        
        int n = nums.length;
        //b[i]表示最大长度是i时，在nums数组中的最小的
        int[] b = new int[n + 1];
        b[0] = Integer.MIN_VALUE;
        
        int max = 0;
        int rClose = 0;
        for(int i = 0; i < n; i++) {
            int start = 0, end = max;
            while(start + 1 < end) {
                int mid = start + (end - start) / 2;
                if(b[mid] < nums[i]) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
            
            if(nums[i] <= b[start]) {
                rClose = start;
            } else if(nums[i] <= b[end]) {
                rClose = end;
            } else {
                rClose = end + 1;
            }
            
            
            b[rClose] = nums[i];
            max = Math.max(max, rClose);
        }
        
        return max;

    }
}
```