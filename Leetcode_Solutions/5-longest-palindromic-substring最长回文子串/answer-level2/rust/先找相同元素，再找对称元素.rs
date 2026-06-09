1）先找相同元素：以index为中心，向两边扩展，即s[left] == s[right] == s[index];
2) 找对称元素：如果s[left-i] == s[right+1], left-=1,right+=1,i+=1;

执行用时 :12 ms, 在所有 Rust 提交中击败了57.78%的用户
内存消耗 :2 MB, 在所有 Rust 提交中击败了100.00%的用户

```
pub fn longest_palindrome(s: String) -> String {
    let ss: Vec<char> = s.chars().collect();
    let len = ss.len();
    if len <= 1 {
        return s;
    }

    let (mut begin, mut end, mut left, mut right, mut max) = (0, 0, 0, 0, 0);
    for i in 0..len {
        left = i;
        right = i;
        while left > 0 && ss[left - 1] == ss[i] {
            left -= 1;
        }
        while right < len - 1 && ss[right + 1] == ss[i] {
            right += 1;
        }

        while left > 0 && right < len - 1 && ss[left - 1] == ss[right + 1] {
            left -= 1;
            right += 1;
        }
        if right - left > max {
            begin = left;
            end = right;
            max = end - begin;
        }
    }

    s[begin..end + 1].to_string()
}
```
