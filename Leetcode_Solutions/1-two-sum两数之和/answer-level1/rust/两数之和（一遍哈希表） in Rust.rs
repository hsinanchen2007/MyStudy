```rust
use std::collections::HashMap;

impl Solution {
    /// ```
    /// use leetcode::a0001_two_numbers::Solution;
    ///
    /// assert_eq!(Solution::two_sum(vec![2, 7, 11 ,15], 9), vec![0, 1]);
    /// ```
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, usize> = HashMap::new();

        for (i, &num) in nums.iter().enumerate() {
            if let Some(&pos) = map.get(&(target - num)) {
                return vec![pos as i32, i as i32];
            }
            map.insert(num, i);
        }

        panic!()
    }
}
```