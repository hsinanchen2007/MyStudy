```
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int l = 0, r = -1;              // [l...r] 滑动窗口范围, 初始区间不存在
        int sum = 0;                    // 存储[l...r]的区间和
        int res = nums.length + 1;      // 存储长度最小的区间

        while ( l < nums.length ) {
            //=========== 下面是滑动窗口 ===========//
            if ( r + 1 < nums.length
                    && sum < s ) {      // 区间和小于s且r+1没有超出nums的边界
                r ++ ;
                sum += nums[r];
            } else {                    // sum >= s 或者 r 已经是数组最后一个元素的下标
                sum -= nums[l];
                l ++ ;
            }
            //=========== 上面是滑动窗口 ===========//

            // 如果 sum >= s, 更新res
            if ( sum >= s ) {
                res = Math.min(res, r - l + 1);
            }
        }
        
        return res == nums.length + 1 ? 0 : res;
    }
}
```
