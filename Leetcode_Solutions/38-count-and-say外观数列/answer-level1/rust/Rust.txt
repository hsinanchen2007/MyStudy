![image.png](https://pic.leetcode-cn.com/eac91f53d7eddfb054a1b3e99144a0cfa0f7cba39b336942fd6dbf40ae9495d2-image.png)

```
impl Solution {
    pub fn count_and_say(n: i32) -> String {
        if n == 1 { return String::from("1"); }
        let last_str = Solution::count_and_say(n - 1);
        let mut curr_str = String::new();
        let mut last_char = None;
        let mut last_char_count = 0;
        for ch in last_str.chars() {
            if last_char == None {
                last_char = Some(ch);
            }
            if ch != last_char.unwrap() {
                curr_str.push_str(&last_char_count.to_string());
                curr_str.push(last_char.unwrap());
                last_char = Some(ch);
                last_char_count = 1;
            } else {
                last_char_count += 1;
            }
        }
        if last_char_count > 0 {
            curr_str.push_str(&last_char_count.to_string());
            curr_str.push(last_char.unwrap());
        }
        curr_str
    }
}
```
