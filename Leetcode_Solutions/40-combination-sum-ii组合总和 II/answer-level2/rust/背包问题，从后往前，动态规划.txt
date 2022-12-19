### 解题思路
rust还是复杂了些，用python的话更简洁

### 代码

```rust
impl Solution {
    // DP
    pub fn combination_sum2(mut candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        if candidates.is_empty() || target <= 0 { return vec![]; }
        candidates.sort_unstable();
        let mut dp = vec![std::collections::BTreeSet::new(); (target + 1) as usize];
        dp[0].insert(vec![]);
        for &c in &candidates {
            for i in (c..=target).rev() {
                let mut mem = std::collections::BTreeSet::new();
                for pre in &dp[(i - c) as usize] {
                    let mut pre = pre.clone();
                    pre.push(c);
                    mem.insert(pre);
                }
                dp[i as usize].extend(mem.into_iter());
            }
        }
        return dp.pop().unwrap().into_iter().collect();
    }
}
```