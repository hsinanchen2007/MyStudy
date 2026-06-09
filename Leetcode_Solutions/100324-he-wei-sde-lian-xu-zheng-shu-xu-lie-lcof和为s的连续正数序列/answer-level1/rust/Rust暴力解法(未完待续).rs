### 解题思路
没啥好说的...主要还是为了熟悉一下Rust语法。抽空补一个双指针法。
### 代码

```rust
impl Solution {
    pub fn range_sum (s: i32, n: i32) -> i32 {
        (s .. n+1).fold(0, |a, b| a + b)
    }

    pub fn find_continuous_sequence(target: i32) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        for i in 1..(target / 2 + 1) {
            for j in 1..(target - i) {
                let i = i as i32;
                let j = j as i32;
                if(Self::range_sum(i, i + j) == target) {
                    res.push((i..(i + j + 1)).collect());
                }
                else if(Self::range_sum(i, i + j) > target) {
                    break;
                }
            }
        }
        res
    }
}
```