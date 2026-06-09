
### 代码

```rust
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut diff = 0;
        let mut min = i32::max_value();
        for n in prices {
            //当前最小值
            min = min.min(n);
            //最大差
            diff = diff.max(n - min)
        }
        diff
    }
}
```