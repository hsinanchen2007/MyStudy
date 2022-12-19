### 解题思路


### 代码

```rust
impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let (mut a, mut b) = (a.chars().rev().peekable(), b.chars().rev().peekable()); 
        let mut result = vec![];
        let mut tmpsum: u8 = 0;
        let mut carry: u8 = 0;
        while a.peek() != None || b.peek() != None || carry != 0 {
            tmpsum = 0;
            if let Some(ch) = a.next() {
                tmpsum += Solution::char_to_binary(ch);
            }

            if let Some(ch) = b.next() {
                tmpsum += Solution::char_to_binary(ch);
            }
            tmpsum += carry;
            carry = tmpsum / 2;
            tmpsum = tmpsum % 2;
            result.push(tmpsum);
        }

        result.iter().rev().map(|bin| Solution::binary_to_char(*bin)).collect::<String>()

    }
    fn char_to_binary(ch: char) -> u8 {
        if ch == '1' {
            1
        } else {
            0
        }
    }

    fn binary_to_char(bin: u8) -> char {
        if bin == 1 {
            '1'
        } else {
            '0'
        }
    }
}
```