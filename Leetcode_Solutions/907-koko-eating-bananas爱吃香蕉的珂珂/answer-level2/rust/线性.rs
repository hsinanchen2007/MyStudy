```rust
impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let sum: u64 = piles.iter().map(|&x| x as u64).sum();
        let start = (sum / h as u64) as i32 + if sum % h as u64 == 0 { 0 } else { 1 };

        for v in start..i32::max_value() {
            let t = piles
                .iter()
                .fold(0, |acc, x| acc + x / v + if x % v == 0 { 0 } else { 1 });
            if t <= h {
                return v;
            }
        }

        unreachable!()
    }
}
```

