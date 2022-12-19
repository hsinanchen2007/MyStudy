## 思路
分别统计
- 总人数:`total_cstm`
- 因为生气而不满意客人的人数: 总损失:`total_loss`
- 因为开技能而产生的局部收益: `gain`
    - 局部收益`gain`的最大值`max_gain`

最后的满意的顾客人数为`total_cstm - total_loss + gain`
很明显, 我们希望开技能产生的收益最大
## 代码
```rust
impl Solution {
    pub fn max_satisfied(customers: Vec<i32>, grumpy: Vec<i32>, x: i32) -> i32 {
        // start from (0,x)
        // end at (len-x-1,len-1)
        let x = x as usize;
        let mut total_loss:i32 = 0;
        let mut total_cstm:i32 = 0;

        for ind in 0..x {
            total_cstm += customers[ind];
            total_loss += customers[ind]*grumpy[ind];
        }

        let mut start:usize = 0;
        let mut end:usize = x;
        let mut gain = total_loss;
        let mut max_gain = gain;

        for ind in x..customers.len() {
            total_cstm += customers[ind];
            let start_loss = customers[start]*grumpy[start];
            let end_loss = customers[end]*grumpy[end];
            gain = gain - start_loss + end_loss;
            total_loss += end_loss;
            if gain > max_gain {
                max_gain = gain;
            }
            start += 1;
            end += 1;
        }

        total_cstm - total_loss + max_gain
    }
}
```
