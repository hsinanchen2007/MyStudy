### 解题思路
此处撰写解题思路

### 代码

```rust
use std::cmp::min;
use std::collections::HashMap;
use std::i32::MAX;
impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        if amount == 0 {
            return 0;
        }
        let mut dp: HashMap<i32, i32> = HashMap::new();
        Self::dfs(&coins, amount, &mut dp)
    }

    fn dfs(coins: &Vec<i32>, amount: i32, dp: &mut HashMap<i32, i32>) -> i32 {
        if amount <= 0 {
            return -1;
        }
        if let Some(r) = dp.get(&amount) {
            return *r;
        }

        for i in coins {
            if *i == amount {
                return 1;
            }
        }

        let mut result = MAX;
        for i in (0..coins.len()).rev() {
            let j = Self::dfs(coins, amount - coins[coins.len() - i - 1], dp);
            if j != -1 {
                result = min(result, j + 1)
            }
        }
        result = if result == MAX { -1 } else { result };
        dp.insert(amount, result);
        result
    }
}

```