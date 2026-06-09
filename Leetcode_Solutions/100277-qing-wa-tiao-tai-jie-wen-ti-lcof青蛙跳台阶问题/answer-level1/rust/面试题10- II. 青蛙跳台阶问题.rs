### rust
![image.png](https://pic.leetcode-cn.com/2ba33e42f21975acd331d99a63eaf85e1ce0d6d45ad521acf105a0643391aef6-image.png)

```rust []
impl Solution {
    pub fn num_ways(n: i32) -> i32 {
        let (mut a, mut b) = (0, 1);
        for _ in 0 .. n + 1 {
            let c = a;
            a = b;
            b = (a + c) % 1000000007;
        }
        a
    }
}
```