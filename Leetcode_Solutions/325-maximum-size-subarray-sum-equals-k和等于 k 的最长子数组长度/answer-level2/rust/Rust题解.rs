![2019-10-17 22-56-18屏幕截图.png](https://pic.leetcode-cn.com/32e1b3fcb995d419b8fd25d35c490b2fb8c4dda304dd130dbc470ce89bbbdf71-2019-10-17%2022-56-18%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

首先，根据提示我们能够求出前缀和`sum[i] == nums[0]+nums[1]+...+nums[i]`
由于我们要找的是一个连续的子区间，因此我们可以枚举这个区间的结尾i
如果以`nums[i]`作为结尾的某个子区间和为k，而我们又知道前缀和`sum[i]`，因此必然前面存在`nums[0]+...+nums[j]==sum[i]-k`。如果我们利用hash表来存储前缀和为T的数组的最短长度是j，那么就可以在`O(1)`的时间内判断是否存在`nums[0]+...+nums[j]==sum[i]-k`。
代码如下：
```rust
use std::collections::HashMap;
use std::cmp::max;

impl Solution {
    pub fn max_sub_array_len(nums: Vec<i32>, k: i32) -> i32 {
        // total 表示前缀和
        let mut total = 0;
        let mut hash = HashMap::new();
        let n = nums.len();
        let mut ans = 0;
        for (i, v) in nums.into_iter().enumerate() {
            total += v;
            let q = total-k;
            // 如果当前和就等于k，那就找到了一个从0..i的区间，由于i是递增的，因此ans就是i+1
            if q == 0 {
                ans = i+1;
            } else if let Some(&idx) = hash.get(&q) {
                // 看前面是否存在0..idx的区间，和为q，确定这个idx
                // 如果找到了，说明存在一个长度为i-idx的区间和为k
                ans = max(ans, i-idx);
            }
            // 利用hash表记录以下和为total的区间最短是0..i
            // 这里利用了rust的entry方法，相当于是如果hash[total]不存在再插入i，否则不做任何处理（因为要求最长区间，因此需要保存最短的0..i）
            hash.entry(total).or_insert(i);
        }
        ans as i32
    }
}
```
