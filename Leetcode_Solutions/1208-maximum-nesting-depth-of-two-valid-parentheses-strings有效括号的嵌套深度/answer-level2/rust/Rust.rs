### 解题思路
参考官方题解

### 代码

```rust
impl Solution {
pub fn max_depth_after_split(seq: String) -> Vec<i32> {
    let mut ans = Vec::new();
    let mut count = 0;
    for &c in seq.as_bytes() {
        if c == b'('{
            count += 1;
            ans.push(count%2);
        }else{
            ans.push(count%2);
            count -= 1;
        }
    }
    ans
}
}
```