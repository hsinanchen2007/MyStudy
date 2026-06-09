执行结果：
通过
显示详情
执行用时 :
0 ms
, 在所有 Rust 提交中击败了
100.00%
的用户
内存消耗 :
2 MB
, 在所有 Rust 提交中击败了
100.00%
的用户
```
impl Solution {
  pub fn sort_string(s: String) -> String {
            let mut ret = String::new();
            let mut v = vec![0; 26];
            for c in s.chars() {
                v[c as usize - 97] += 1;
            }
            while ret.len() < s.len() {
                for n in 0..26u8 {
                    if v[n as usize] > 0 {
                        ret.push((n + 97) as char);
                        v[n as usize] -= 1;
                    }
                }
                for n in (0..=25u8).rev() {
                    if v[n as usize] > 0 {
                        ret.push((n + 97) as char);
                        v[n as usize] -= 1;
                    }
                }
            }
            ret
        }
}
```
