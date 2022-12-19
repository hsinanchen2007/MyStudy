## 思路:

大家做这道题之前, 先做一下[53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/) | [题解链接](https://leetcode-cn.com/problems/maximum-subarray/solution/sumij-sum0j-sum0iqiu-jie-by-powcai)

思路一: 类似滑动窗口的感觉

`product(i, j) = product(0, j) / product(0, i)` 从数组`i`到`j` 的累乘等于 从数组开头到`j`的累乘除以从数组开头到`i` 的累乘(这里先忽略`0`的情况), 要考虑三种情况

累乘的乘积等于`0`,就要重新开始

累乘的乘积小于`0`, 要找到前面最大的负数, 这样才能保住从`i`到`j`最大

累乘的乘积大于`0`, 要找到前面最小的正数, 同理!

代码如下:

```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums: return
        # 目前的累乘
        cur_pro = 1
        # 前面最小的正数
        min_pos = 1
        # 前面最大的负数
        max_neg = float("-inf")
        # 结果
        res = float("-inf")
        for num in nums:
            cur_pro *= num
            # 考虑三种情况
            # 大于0
            if cur_pro > 0:
                res = max(res, cur_pro // min_pos)
                min_pos = min(min_pos, cur_pro)
            # 小于0
            elif cur_pro < 0:
                if max_neg != float("-inf"):
                    res = max(res, cur_pro // max_neg)
                else:
                    res = max(res, num)
                max_neg = max(max_neg, cur_pro)
            # 等于0 
            else:
                cur_pro = 1
                min_pos = 1
                max_neg = float("-inf")
                res = max(res, num)
        return res 
```

思路二, 动态规划[^1]

我们只要记录前`i`的最小值, 和最大值, 那么 `dp[i] = max(nums[i] * pre_max, nums[i] * pre_min, nums[i])`, 这里`0` 不需要单独考虑, 因为当相乘不管最大值和最小值,都会置`0`

```python []
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums: return 
        res = nums[0]
        pre_max = nums[0]
        pre_min = nums[0]
        for num in nums[1:]:
            cur_max = max(pre_max * num, pre_min * num, num)
            cur_min = min(pre_max * num, pre_min * num, num)
            res = max(res, cur_max)
            pre_max = cur_max
            pre_min = cur_min
        return res
```



```java []
class Solution {
    public int maxProduct(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int res = nums[0];
        int pre_max = nums[0];
        int pre_min = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int cur_max = Math.max(Math.max(pre_max * nums[i], pre_min * nums[i]), nums[i]);
            int cur_min = Math.min(Math.min(pre_max * nums[i], pre_min * nums[i]), nums[i]);
            res = Math.max(res, cur_max);
            pre_max = cur_max;
            pre_min = cur_min;
        }
        return res;
    }
}
```

思路三: 根据符号的个数[^2]

当负数个数为偶数时候, 全部相乘一定最大

当负数个数为奇数时候, 它的左右两边的负数个数一定为偶数, 只需求两边最大值

当有`0`情况,重置就可以了

```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        reverse_nums = nums[::-1]
        for i in range(1, len(nums)):
            nums[i] *= nums[i - 1] or 1
            reverse_nums[i] *= reverse_nums[i - 1] or 1
        return max(nums + reverse_nums)
```



[^1]: <https://leetcode.com/problems/maximum-product-subarray/discuss/48252/Sharing-my-solution%3A-O(1)-space-O(n)-running-time>
[^2]: <https://leetcode.com/problems/maximum-product-subarray/discuss/183483/Easy-and-Concise-Python>



