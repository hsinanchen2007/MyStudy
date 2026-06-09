```Go
func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 { return "" }
	str, char, ptr := &strings.Builder{}, byte(0), 0
	for {
		for i := range strs {
			if ptr > len(strs[i]) - 1 {
				return str.String()
			} else if i == 0 {
				char = strs[i][ptr]
			} else if strs[i][ptr] != char {
				return str.String()
			}
		}
		str.WriteByte(strs[0][ptr])
		ptr += 1
	}
}
```

```Rust
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        if strs.len() == 0 || strs[0] == "" { return "".to_string() };
        if strs.len() == 1 { return strs[0].clone() }
        let mut result = String::from("");
        let mut temp : u8 = 0;
        let mut ptr = 0;

        loop {
            for i in 0..strs.len() {
                if ptr >= strs[i].len() {
                    return result.to_string();
                } else if i == 0 {
                    temp = strs[i].as_bytes()[ptr];
                } else if strs[i].as_bytes()[ptr] != temp {
                    return result.to_string();
                }
            }
            let str = strs[0].as_bytes()[ptr];
            result.push(str as char);
            ptr += 1;
        }
    }
}
```