
![Screenshot from 2020-04-06 15-25-04.png](https://pic.leetcode-cn.com/5c15c9aa70397e1d9b6725f298c43f1d33a67d4ea5dbc040a59a33c59a0170fe-Screenshot%20from%202020-04-06%2015-25-04.png)

使用数组稍微好点

```rust
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut start: usize = 0;
        let mut len = 0;
        let mut max_len = 0;
        let mut m: [i32; 128] = [-1; 128];
        let mut n: usize = 0;
        let mut arr = s.as_bytes();
        let arr_size = arr.len();
        if arr_size == 0 {
            return 0;
        }
        while n < arr_size {
            let e = arr[n] as usize;
            if m[e] >= 0 {
                let index = m[e] as usize;
                len = n - start;
                if len > max_len {
                    max_len = len;
                }
                //update index
                start = index + 1;
                n = start;
                let mut i = 0;
                while i < m.len() {
                    m[i] = -1;
                    i += 1;
                }
                continue;
            } else {
                //not repeat
                len = n - start + 1;
                m[e] = n as i32;
                if len > max_len {
                    max_len = len;
                }
            }
            n += 1;
        }
        return max_len as i32;
    }
}
```