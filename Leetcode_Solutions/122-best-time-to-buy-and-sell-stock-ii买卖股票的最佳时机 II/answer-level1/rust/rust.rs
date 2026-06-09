### 解题思路
只要第二天的价格比前一天的价格高就卖出

### 代码

```rust
impl Solution {
    //只要第二天的价格比前一天的价格高就卖出
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut r = 0;
        for i in 1..prices.len() {
            if prices[i] > prices[i-1] {
                r += prices[i]-prices[i-1];
            }
        }
        r
    }
}
```