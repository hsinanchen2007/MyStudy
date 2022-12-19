8ms 双100%

* 这道题要找最长的,如果相同就要字典序最小的. 因此先进行"双关键字"排序.
* 由于每次都会用d中一个字符串和s进行比较, 每次都要重复地扫描s比较耗时,可以进行预处理, 利用hash[char][Vec<index>], 记录s中每个字符出现的下标.
* 每次判断d中某个字符串x是否是s的子序列时, 利用一个指针t记录已经扫到s的哪个下标了. 然后利用hash表找到x[i]出现的所有下标,利用二分找出大于t的最小的那个下标. 这样不用挨个扫描, 可以快进

```rust
use std::collections::HashMap;

impl Solution {
    pub fn find_longest_word(s: String, mut d: Vec<String>) -> String {
        if s.is_empty() || d.is_empty() {
            return "".to_string();
        }
        d.sort_by(|a,b| { // 双关键字排序
            if a.len() == b.len() {
                return a.cmp(b);
            }
            b.len().cmp(&(a.len()))
        });
        let mut hash = HashMap::new();
        for (idx, &c) in s.as_bytes().iter().enumerate() {
            hash.entry(c).or_insert(vec![]).push(idx); // 记录s中每个字符出现的位置
        }
        for ds in d {
            let mut pos = None; // pos 记录已经扫描到s的哪个位置了(单调递增)
            let mut ok = true;
            for dc in ds.as_bytes() {
                if let Some(arr) = hash.get(dc) {  // 判断当前字符是否在s中出现
                    let next = pos.map_or(0, |v| v+1); // 如果出现, 那么它在s中的下标至少是next(即pos+1)
                    match arr.binary_search(&next) {
                        Ok(idx) => {
                            pos = Some(next);
                        },
                        Err(idx) => {
                            if idx == arr.len() { // 在s[pos+1..]中已经找不到这个字符了
                                ok = false;
                                break;
                            }
                            pos = Some(arr[idx]);
                        },
                    }
                } else {
                    ok = false;
                    break;
                }
            }
            if ok {
                return ds;
            }
        }
        "".to_string()
    }
}
```