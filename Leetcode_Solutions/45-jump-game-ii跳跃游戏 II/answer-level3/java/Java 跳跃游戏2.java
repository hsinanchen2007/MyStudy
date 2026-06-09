### 解题思路
第i次跳跃，会得到一个范围区间，这个区间内任意一点都可以是第i+1次跳跃的起点。
我们将每一次跳跃的区间记录下来，当第一次右区间触碰到数组的右边界时我们的任务就完成了。
那么如何维护这个区间呢？
首先，每一次跳跃的左区间是上一次跳跃右区间+1（因为不需要考虑无解的情况，也就是当我们跳到数组的任意位置时都可以至少在这个位置往后跳一步），而第i+1次右区间应该是第i次区间内某个位置可以跳到最远的距离。

### 代码

```java
class Solution {
    public int jump(int[] nums) {
        if(nums == null || nums.length < 2) return 0 ;
        int left = 0 , right = 0 , count = 0 , n = nums.length - 1 ;
        while(right < n){
            count++ ;
            int max_r = 0 ;
            for(int i = left ; i <= right ; i++){
                max_r = Math.max(max_r,i+nums[i]) ;
            }
            left = right + 1 ;
            right = max_r ;
        }
        return count ;
    }
}
```