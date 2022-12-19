
遍历 vector 的时候注意使用borrow (&), 可以避免 move, 让速度更快.

```rs
impl Solution {
    pub fn has_groups_size_x(deck: Vec<i32>) -> bool {
        if deck.is_empty() {
            return false;
        }
        fn gcd(a: usize, b: usize) -> usize {
            let mut a = a;
            let mut b = b;
            if a < b {
                std::mem::swap(&mut a, &mut b);
            }
            let r = a % b;
            if r == 0 {
                b
            } else {
                gcd(b, r)
            }
        }
        let mut freq = vec![0;10000];
        for &x in &deck {
            freq[x as usize] += 1;
        }
        let mut g = 99999;
        for &f in &freq {
            if f != 0 {
                if g == 99999 {
                    g = f
                } else { 
                    g = gcd(g, f);
                }
            }
        }
        g >= 2
    }
}
```