先排序后遍历

1   1   2   5   5   6   9
↓   ↓   ↓   ↓   ↓   ↓   ↓
1   2   3   5   6   7   9

需要(1-1)+(2-1)+(3-2)+(5-5)+(6-5)+(7-6)+(9-9)次

```rust
impl Solution {
    pub fn min_increment_for_unique(a: Vec<i32>) -> i32 {
        if a.is_empty() {
            return 0;
        }
        let mut a = a;
        a.sort();
        let mut min = 0;
        let mut k = a[0];
        for i in a {
            if k >= i {
                min += k - i;
                k += 1;
            } else {
                k = i + 1;
            }
        }
        min
    }
}
```
