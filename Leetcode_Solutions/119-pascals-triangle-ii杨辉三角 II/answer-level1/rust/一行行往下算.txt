### 解题思路
一行行往下算

### 代码

```rust
impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let mut res = vec![];
        for i in 0..=row_index as usize{
            res.push(1);
            for l in (1..i as usize).rev(){
                res[l]+=res[l-1];
            }
        }
        res
    }
}
```