过2遍数组，记录左右小于当前位置的个数
再找最大值
```rust
impl Solution {
    pub fn longest_mountain(a: Vec<i32>) -> i32 {
        if a.len() <3 {
            return 0;
        }
        let mut left_lt = vec![0;a.len()];
        let mut right_lt = vec![0;a.len()];
        for i in 1..a.len() {
            if a[i-1] < a[i] {
                left_lt[i] = left_lt[i-1] + 1;
            }
        }
        for i in (0..a.len()-1).rev() {
            if a[i+1] < a[i] {
                right_lt[i] = right_lt[i+1] + 1;
            }
        }
        let mut res = 0;
        for i in 1..a.len()-1 {
            res = res.max(if left_lt[i]>0 && right_lt[i]>0 {left_lt[i]+right_lt[i]+1} else {0});
        }
        res
    }
}

```
