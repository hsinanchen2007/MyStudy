### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn last_remaining(n: i32, m: i32) -> i32 {
        let mut f = 0; //n==1
        for i in 2..n+1{
            f = (f+m)%i;
        }
        f
    }
}
```