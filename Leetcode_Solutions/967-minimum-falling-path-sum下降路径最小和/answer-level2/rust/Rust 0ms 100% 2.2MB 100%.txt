### 解题思路
![image.png](https://pic.leetcode-cn.com/1f298016828a7b72e789221c8ad5040f5faafd0c697503016123c0f7da5c5909-image.png)


### 代码

```rust
use std::cmp::min;
impl Solution {
    pub fn min_falling_path_sum(a: Vec<Vec<i32>>) -> i32 {
        let size = a.len();
        let mut dp = a;
        for row in 2..=size {
            let row = size - row;
            for col in 0..size {
                let next_row = row + 1;
                if col == 0 {
                    dp[row][col] += min(dp[next_row][col], dp[next_row][col + 1]);
                } else if col == size - 1 {
                    dp[row][col] += min(dp[next_row][col], dp[next_row][col - 1]);
                } else {
                    dp[row][col] += Solution::min3(
                        dp[next_row][col - 1],
                        dp[next_row][col],
                        dp[next_row][col + 1],
                    );
                }
            }
        }

        let mut res = std::i32::MAX;
        for i in &dp[0] {
            res = min(res, *i);
        }
        res
    }

    #[inline]
    pub fn min3<T: Ord>(v1: T, v2: T, v3: T) -> T {
        v3.min(v1.min(v2))
    }
}
```