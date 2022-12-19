### 解题思路
见注释

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int lo = 0 , hi = nums.length-1;
        //保证mid下表不越界；
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(nums[mid] == mid){
                //出口在mid右侧，即lo的值；
                lo = mid + 1;
            }else{
                //若一直在这里，最后出口为0，即lo的初值.
                hi = mid - 1;
            }
        }
        return lo;
    }
}
```