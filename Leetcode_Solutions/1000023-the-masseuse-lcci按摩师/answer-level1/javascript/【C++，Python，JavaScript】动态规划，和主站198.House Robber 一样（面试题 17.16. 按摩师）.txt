

####  解题思路

- 本题和 [198. 打家劫舍](https://github.com/azl397985856/leetcode/blob/master/problems/198.house-robber.md) 完全一样，属于换皮题。

- 主站还有一个类似题  [213. 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/)，信息是基本一样，只是多了个条件  “首尾只能偷一个”。

- 另外还有一个类似题 [337. 打家劫舍 III](https://leetcode-cn.com/problems/house-robber-iii/)，信息是基本一样，只是数据结构从数组变成了树。


大家可以三道题对比起来做。

这是一道非常典型且简单的动态规划问题，但是在这里我希望通过这个例子，让大家对动态规划问题有一点认识。

为什么别人的动态规划可以那么写，为什么没有用 `dp` 数组就搞定了。比如别人的爬楼梯问题怎么就用 `fibnacci` 搞定了？为什么？在这里我们就来看下。

思路还是和其他简单的动态规划问题一样，我们本质上在解决 `对于第[i] 个人，我接待还是不接待。` 的问题。判断的标准就是总价值哪个更大， 那么对于接待的话 `就是当前接待的的价值 + dp[i - 2]`

> i - 1 不能接待，因为要休息，不然会虚脱

如果不接待的话，就是 `dp[i - 1]`.

> 这里的 dp 其实就是`子问题`.

状态转移方程也不难写 `dp[i] = Math.max(dp[i - 2] + nums[i - 2], dp[i - 1]);`（注：这里为了方便计算，令 `dp[0]`和 `dp[1]` 都等于 0，所以 `dp[i]` 对应的是 `nums[i - 2]`）



#### 代码


```python []
class Solution:
    def massage(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * (n + 2)
        ans = 0
        for i in range(2, n + 2):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 2])
            ans = max(ans, dp[i])
        return ans
```



```js []
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    const dp = [];
    dp[0] = 0;
    dp[1] = 0;

    for (let i = 2; i < nums.length + 2; i++) {
        dp[i] = Math.max(dp[i - 2] + nums[i - 2], dp[i - 1]);
    }

    return dp[nums.length + 1];
};

```

**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

#### 优化的动态规划


我们仔细观察的话，其实我们只需要保证前一个 `dp[i - 1] 和 dp[i - 2]` 两个变量就好了
比如我们计算到 `i = 6` 的时候，即需要计算 `dp[6]` 的时候， 我们需要 `dp[5]`, `dp[4]`，但是我们
不需要 `dp[3], dp[2]` ...

因此代码可以简化为：

```js []
let a = 0;
let b = 0;

for (let i = 0; i < nums.length; i++) {
  const temp = b;
  b = Math.max(a + nums[i], b);
  a = temp;
}

return b;
```

如上的代码，我们可以将空间复杂度进行优化，从 $O(n)$ 降低到 $O(1)$,
类似的优化在 `DP` 问题中不在少数。

> 动态规划问题是递归问题查表，避免重复计算，从而节省时间。
> 如果我们对问题加以分析和抽象，有可能对空间上进一步优化

#### 代码

```c++ []
class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.empty()) return 0;
        auto sz = nums.size();
        if (sz == 1) return nums[0];
        auto prev = nums[0];
        auto cur = max(prev, nums[1]);
        for (auto i = 2; i < sz; ++i) {
            auto tmp = cur;
            cur = max(nums[i] + prev, cur);
            prev = tmp;
        }
        return cur;
    }
};
```

```python []
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0

        length = len(nums)
        if length == 1:
            return nums[0]
        else:
            prev = nums[0]
            cur = max(prev, nums[1])
            for i in range(2, length):
                cur, prev = max(prev + nums[i], cur), cur
            return cur
```



**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$