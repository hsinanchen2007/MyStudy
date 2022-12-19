这道题使用滑动窗口的思路基本都是一样的，主要的点在于，如何判断窗口中只有最多两个不同的字符。官方解法是利用hashmap，当hashmap.len > 2说明多了一个新字符。但其实不需要hashmap，由于这里最多只有两个字符，因此可以使用两个变量来保存窗口中的字符的最后一次出现的位置。

```rust
impl Solution {
    pub fn length_of_longest_substring_two_distinct(s: String) -> i32 {
        let n = s.len();
        if n < 3 {
            return n as i32;
        }
        let bs = s.as_bytes();
        let mut l = 0;
        let mut r = 0;
        let mut ans = 2;
        let mut a = None;
        let mut b = None;
        while r < n {
            if a.is_none() || bs[r] == bs[a.unwrap()] {
                a = Some(r);
            } else if b.is_none() || bs[r] == bs[b.unwrap()] {
                b = Some(r);
            } else {
                let pa = a.unwrap();
                let pb = b.unwrap();
                if pa < pb {
                    l = pa+1;
                    a = Some(r);
                } else {
                    l = pb+1;
                    b = Some(r);
                }
            }
            ans = ans.max(r-l+1);
            r += 1;
        }
        ans as i32
    }
}
```