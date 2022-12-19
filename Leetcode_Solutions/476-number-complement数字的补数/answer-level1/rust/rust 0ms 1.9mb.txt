![image.png](https://pic.leetcode-cn.com/5eb31de7ddf6538d9cf81ae5927da5aa3da7ddc93fe398031d228a45cdb3c038-image.png)

```rust
impl Solution {
    pub fn find_complement(num: i32) -> i32 {
        let lz = num.leading_zeros();
        !num << lz >> lz
    }
}
```
