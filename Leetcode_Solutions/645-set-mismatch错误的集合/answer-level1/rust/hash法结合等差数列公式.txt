1.利用hash结构找到数组中重复的元素E；
2.计算这个数组的和C；
3.利用等差数列求和公式![gongshi.png](https://pic.leetcode-cn.com/67266b6dd8b6dd2a0690954ed6e778ae3550d7132c7246eeb9a07f22e149c75c-gongshi.png)
求出数组正常情况下的总和S，此时丢失的整数L=S-C+E,由于只遍历了一遍，所以时间复杂度为O(n),由于hash表的存在，空间复杂度为O(n)

```rust
use std::collections::HashSet;
impl Solution {
    pub fn find_error_nums(nums: Vec<i32>) -> Vec<i32> {
        let length = nums.len() as i32;
        let mut set:HashSet<i32> = HashSet::new();
        let mut extra = 0;
        let mut sum = 0;
        for i in nums {
            if set.contains(&i) {
                extra = i;
            } else {
                set.insert(i);
            }
            sum += i;
        }
        let std = (length * length + length) / 2;
        let lost = std - sum + extra;
        return vec![extra,lost];
    }
}
```

