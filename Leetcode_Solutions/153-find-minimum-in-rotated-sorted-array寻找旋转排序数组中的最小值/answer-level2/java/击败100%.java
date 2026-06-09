### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        if(n == 1){
            return nums[0];
        }

        int lo = 0;
        int hi = n - 1;
        while(hi > lo){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] < nums[0]){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }

        return nums[hi] < nums[0]? nums[hi] : nums[0];       
    }
}
```