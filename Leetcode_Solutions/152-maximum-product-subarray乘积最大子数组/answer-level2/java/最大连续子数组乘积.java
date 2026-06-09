### 解题思路
由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值imin

### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        if(nums.length == 1) return nums[0];
        int imax = 1, imin = 1;
        int max = Integer.MIN_VALUE;
        //由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值imin
        for(int i = 0 ; i < nums.length ; i++){
            if(nums[i] < 0){
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }
            imax = Math.max(nums[i]*imax,nums[i]);
            imin = Math.min(nums[i]*imin,nums[i]);
            max = Math.max(max,imax);
        }
        return max;
    }
}
```