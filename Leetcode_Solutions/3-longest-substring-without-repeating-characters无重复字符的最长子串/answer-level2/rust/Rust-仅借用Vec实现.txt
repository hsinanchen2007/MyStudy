### 解题思路
题目要求我们求无重复的最长子串,因此我们需要一个Vec存储字符,一个count进行计数,当碰到在Vec内的字符,进行计数的大小比较和while循环弹出数组的首位;当碰到非Vec内的字符,先将其压入,后判断count是否需要更新

### 代码

```rust
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut v: Vec<u8> = Vec::new();
        let mut count = 0;
        for i in s.bytes() {
            if v.contains(&i) {
                if v.len() >= count {
                    count = v.len();
                }
                while (v.contains(&i)) {
                    v.remove(0);
                }
                v.push(i);
            } else {
                v.push(i);
                if v.len() >= count {
                    count = v.len();
                }
            }
        }
        count as i32
    }
}
```