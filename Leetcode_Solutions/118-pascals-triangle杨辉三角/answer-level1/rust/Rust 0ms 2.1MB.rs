![image.png](https://pic.leetcode-cn.com/4f23abd27f469236656a36c97155787701af50ed5897e54c5202904f42975c04-image.png)


### 代码

```rust
impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut t = Vec::with_capacity(num_rows as usize);
        for i in 0..num_rows as usize {
            let mut v: Vec<i32> = (0..i + 1).map(|_| 1).collect();
            if i > 0 {
                for j in 1..i {
                    let last_row: &Vec<i32> = &t[i - 1];
                    v[j] = last_row[j - 1] + last_row[j];
                }
            }
            t.push(v);
        }
        t
    }
}
```