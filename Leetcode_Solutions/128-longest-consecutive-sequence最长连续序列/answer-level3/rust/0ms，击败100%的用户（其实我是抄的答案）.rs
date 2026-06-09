### 解题思路
我自己做的时候想不出来怎么O(n)做出来，看了答案才恍然大悟觉得这题很简单。

先考虑最简单的问题：给定一个排序好的数组，找出最长的连续子序列。
这个估计大家都会做：
遍历数组，检查当前数字是否和前一个连续，若连续则记录连续的数字个数+1；若不连续，则更新到一个max值上去。最后返回max。


再看这题，能否利用上面对思路来做呢？也是可以的。只需要一点逆向思维，转换一下。
之前是：检查存在两个的数字是否连续。
现在是：检查两个连续的数字是否存在。

具体做法；
先存到hashset里，然后遍历set，检查当前数字的下一个连续数字是否在set中，若存在则记录连续的数字个数+1；若不存在，则更新到一个max值上去。最后返回max。


### 代码

```rust
use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        if len <= 1 {
            return len as i32;
        }
        let mut st = HashSet::new();
        for x in nums {
            st.insert(x);
        }
        let mut longest = 0;
        for x in st.iter() {
            if st.contains(&(x - 1)) == false {
                let mut cur = x + 1;
                let mut local_longest = 1;
                while st.contains(&cur) {
                    cur += 1;
                    local_longest += 1;
                }
                longest = std::cmp::max(longest, local_longest);
            }
        }
        longest
    }
}
```