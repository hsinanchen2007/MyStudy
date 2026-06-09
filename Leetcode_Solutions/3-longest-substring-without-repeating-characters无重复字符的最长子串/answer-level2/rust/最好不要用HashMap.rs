![Screenshot from 2020-04-06 13-39-39.png](https://pic.leetcode-cn.com/3bdd7e387011171fe49bc0ff0c5fca069bfd1bc8e3e89926b137e98d00512fc9-Screenshot%20from%202020-04-06%2013-39-39.png)

使用HashMap后耗时感人

```rust
use std::collections::HashMap;
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut start: usize = 0;
        let mut len = 0;
        let mut max_len = 0;
        let mut map: HashMap<u8, usize> = HashMap::new();
        let mut n: usize = 0;
        let mut arr = s.as_bytes();
        let arr_size = arr.len();
        if arr_size == 0 {
            return 0;
        }
        while n < arr_size {
            let e = arr[n];
            match map.get(&e) {
                Some(v) => {
                    //repeat
                    let index = *v;
                    len = n - start;
                    if len > max_len {
                        max_len = len;
                    }

                    //update index
                    start = index + 1;
                    n = start;
                    map.clear();
                    continue;
                }
                None => {
                    //not repeat
                    len = n - start + 1;
                    map.insert(e, n);
                    if len > max_len {
                        max_len = len;
                    }
                }
            }
            n += 1;
        }
        return max_len as i32;
    }
}
```