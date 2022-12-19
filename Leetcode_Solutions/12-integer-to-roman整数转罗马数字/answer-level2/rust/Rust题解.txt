
```rust
impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let key: [i32; 13] = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
        let value: [&str; 13] = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];
        let mut result = String::new();
        let mut temp = num;
        for i in 0..13 {
            while temp >= key[i] { 
                result.push_str(value[i]);
                temp -= key[i];
            }
            
        }

        result
    }
}
```