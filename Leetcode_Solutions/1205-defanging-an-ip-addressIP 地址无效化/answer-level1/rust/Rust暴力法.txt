```
impl Solution {
    pub fn defang_i_paddr(address: String) -> String {
        let mut result = String::new();
        for i in address.chars() {
            if i=='.'{
                result.push_str("[.]");
            }else{
                result.push(i);
            }
        }
        result
    }
}
```
