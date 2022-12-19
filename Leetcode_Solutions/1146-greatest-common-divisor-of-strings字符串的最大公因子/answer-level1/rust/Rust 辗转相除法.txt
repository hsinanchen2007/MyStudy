### 解题思路
与数字 gcd 类似，直接上代码吧（

顺便 Rust 的这个迭代器写法是真的舒适。

### 代码

```rust
impl Solution {
    fn rem_of_u8_slice<'a>(a1: &'a [u8], a2: &[u8]) -> Option<&'a [u8]> {
        let compare_len = a1.len().checked_div(a2.len()).unwrap_or(0) * a2.len();
        if a1.iter().zip(a2.iter().cycle()).take(compare_len).all(|(b1, b2)| b1 == b2) {
            Some(&a1[compare_len..])
        } else {
            None
        }
    }

    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        let mut a1 = str1.as_bytes();
        let mut a2 = str2.as_bytes();

        while let Some(rem) = Solution::rem_of_u8_slice(a1, a2) {
            if rem.len() == 0 {
                return std::str::from_utf8(a2).unwrap().to_string();
            }

            a1 = a2;
            a2 = rem;
        }

        "".to_string()
    }
}
```