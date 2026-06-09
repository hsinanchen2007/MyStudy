### 解题思路

[https://doc.rust-lang.org/std/iter/trait.Iterator.html#method.fold](https://doc.rust-lang.org/std/iter/trait.Iterator.html#method.fold)

![image.png](https://pic.leetcode-cn.com/db50ef32ad69ee845d072724cb6525fd2174e6300706555771e5bea30e022beb-image.png)

### 代码

```rust []
impl Solution {
    pub fn sum_nums(n: i32) -> i32 {
        (1..(n + 1)).fold(0, |sum, x| sum + x)
    }
}
```