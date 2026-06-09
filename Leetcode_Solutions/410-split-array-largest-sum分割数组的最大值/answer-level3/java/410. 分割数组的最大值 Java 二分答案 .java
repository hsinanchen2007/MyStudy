### 代码

```java
/**
 * 二分答案
 * (如果数组中有负数, 那么二分答案就不好用了, 就需要动态规划)
 * 初始答案区间 [max, sum]
 * 根据 "使得每个子数组的和都不超过 mid 的前提下, 最少分成多少段" 的段数与 m 比较
 * 来折半答案区间
 */
class Solution {
    public int splitArray(int[] nums, int m) {
        // 初始计算 l, r
        long l = 0, r = 0;
        for (int num : nums) {
            l = Math.max(l, num);
            r += num;
        }
        // 二分过程, 当答案区间 [l, r] 只剩两个元素时停止 
        while (l + 1 < r) {
            long mid = (l + r) / 2;
            int cnt = split(nums, mid);
            if (cnt <= m) { // 当最少分成的段数小于 m 时是可行的, 因为都是正数, 所以一定可以再分出几段最终达到 m 段, 使得每段的和都不超过 mid
                r = mid;
            } else {
                l = mid;
            }
        }
        // 额外判断 [l, r] 的两个元素哪个是正确答案
        return split(nums, l) <= m ? (int)l : (int)r;
    }

    // 统计每一段的和不超过 limit 的前提下, nums 最少可以分成多少段
    // 其实这里相当于贪心
    private int split(int[] nums, long limit) {
        int cnt = 1;
        long sum = 0;
        for (int num : nums) {
            if (sum + num > limit) {
                cnt++;
                sum = num;
            } else {
                sum += num;
            }
        }
        return cnt;
    }
}
```