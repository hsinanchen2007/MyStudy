![image.png](https://pic.leetcode-cn.com/bf69eaa487bbb81d7ef0c9eb3661c34ea9403b866383fec2f44461a5d4cf3600-image.png)

```rust
impl Solution {
    pub fn frequency_sort(s: String) -> String {
        let mut bucket = vec![(0,0);256];
        for b in s.bytes() {
            bucket[b as usize].0 += 1;
            bucket[b as usize].1 = b;
        }
        bucket.sort_by(|a, b| b.0.cmp(&a.0));
        let mut res = String::new();
        for (times, ch) in bucket {
            for _ in 0..times {
                res.push(ch as char);
            }
        }
        res
    }
}
```

