### 解题思路

[Manacher Algorithm](https://ethsonliu.com/2018/04/manacher.html)(0ms|2MB)

### 代码

```rust []
impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        /* Manacher Algorithm
         * step1: add '$''#' into string
         * The character `$` here is just to prevent overbounds
         * there is an even palindrome `abba` and an odd palindrome `opxpo` in `s="abbahopxpo"`,
         * which are converted into `#a#b#b#a#` and `#o#p#x#p#o#`,
         * and the length is converted into odd
         */
        let mut new_str = vec!['$', '#'];
        for ch in s.chars() {
            new_str.push(ch);
            new_str.push('#');
        }
        new_str.push('\0');

        // length of the new string
        let len = new_str.len();

        // Define a secondary array p[],
        // where p[i] represents the radius of the longest palindrome centered on i.
        let mut p = vec![0usize; len];

        // `max_len`: The length of the longest palindrome string in the original string
        let mut max_len = 0usize;

        // Define two variables, `mx` and` id`
        // `mx` represents the right boundary of the longest palindrome centered on` id`,
        // which is `mx = id + p[id]`
        let mut id = 0usize;
        let mut mx = 0usize;
        for i in 1..(len - 1) {
            if i < mx {
                p[i] = p[2 * id - i].min(mx - i);
            } else {
                p[i] = 1;
            }

            while new_str[i - p[i]] == new_str[i + p[i]] {
                p[i] += 1;
            }

            if mx < i + p[i] {
                id = i;
                mx = i + p[i];
            }
            // `p[i] - 1` is exactly the length of
            // the longest palindrome string in the original string
            max_len = max_len.max(p[i] - 1);
        }

        /* Get longest palindromic substring
         * left: left boundery of the longest palindromic substring
         * right: right boundery of the longest palindromic substring
         */
        let left = p.iter().position(|&x| x == (max_len + 1)).unwrap() - max_len + 1;
        let right = left + max_len * 2;
        let mut longest_palindrome_substring = String::from("");
        for i in left..right {
            if new_str[i] != '#' {
                longest_palindrome_substring.push(new_str[i]);
            }
        }

        /* Return longest palindromic substring */
        longest_palindrome_substring
    }
}
```