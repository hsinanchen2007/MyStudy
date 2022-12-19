### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int ret = Integer.MIN_VALUE ;
        int series = 0 ;
        for (int i=0 ; i < nums.length ; i++) {
            series += nums[i] ;
            ret = Math.max(ret,series) ;
            if (series < 0) {
                series = 0 ;
            }
        }
        return ret ;
    }
}
```