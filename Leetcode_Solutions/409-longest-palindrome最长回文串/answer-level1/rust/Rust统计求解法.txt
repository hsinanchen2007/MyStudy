### 解题思路
根据回文字符串的特性，可以知道其中只可能有一个字母的数量为奇数，其余均为偶数，所以可以通过对其进行统计并排列计算出结果。

### 代码

```rust
impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut char_vec = vec![0; 52];
        for c in s.chars() {
            if c.is_uppercase() {
                char_vec[c as usize - 'A' as usize] += 1;
            } else {
                char_vec[c as usize - 'a' as usize + 26] += 1;
            }
        }
        char_vec.sort();
        char_vec.reverse();
        let mut res = 0;
        let mut flag = false;
        for seq in char_vec {
            if seq % 2 == 0 {
                res += seq;
            }else{
                if flag{
                    res += (seq - 1);
                }else{
                    res += seq;
                    flag = true;
                }
            }
        }


        res
    }
}
```