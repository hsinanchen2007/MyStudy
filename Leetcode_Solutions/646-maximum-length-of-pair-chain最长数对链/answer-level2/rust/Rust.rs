### 解题思路
没写，懒得写

### 代码

```rust
impl Solution {
    pub fn find_longest_chain(pairs: Vec<Vec<i32>>) -> i32 {
        let mut pairs = pairs;
        pairs.sort_by_key(|p| p[1]);
        let mut t = pairs[0][1];
        let mut count = 1;
        for p in pairs {
            if p[0] > t {
                count += 1;
                t = p[1];
            }
        }
        count
    }
}
```