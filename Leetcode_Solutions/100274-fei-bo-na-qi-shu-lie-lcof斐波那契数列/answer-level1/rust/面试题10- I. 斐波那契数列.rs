### rust

![image.png](https://pic.leetcode-cn.com/b977699a636b6dd6b432584277edda5c5d01cd7d69d97cdb69e9c444da0c8131-image.png)

```rust []
impl Solution {
    pub fn fib(n: i32) -> i32 {
        let (mut a, mut b) = (0, 1);
        for _ in 0..n {
            let c = a;
            a = b;
            b = (a + c) % 1000000007;
        }
        a
    }
}
```