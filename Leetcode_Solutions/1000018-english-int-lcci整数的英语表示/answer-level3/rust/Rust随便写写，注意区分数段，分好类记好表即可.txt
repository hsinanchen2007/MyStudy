```rust
impl Solution {
    const DIGITS :[&'static str; 20] = ["Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"];

    const TENS_DIGITS :[&'static str; 10] = ["", "",
        "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"];

    pub fn number_to_words(num: i32) -> String {
        if num == 0 {
            return String::from("Zero");
        }
        let mut num = num;
        let billion = num / (1000000000);
        num %= (1000000000);
        let million = num / (1000000);
        num %= (1000000);
        let thousand = num / 1000;
        num %= (1000);
        let hundred = num;
        let mut ans = String::new();

        if billion > 0 {
            ans.push_str(Self::solve_within_1000(billion).as_str());
            ans.push_str(" Billion");
        }
        if million > 0 {
            if !ans.is_empty() {
                ans.push_str(" ");
            }
            ans.push_str(Self::solve_within_1000(million).as_str());
            ans.push_str(" Million");
        }
        if thousand > 0 {
            if !ans.is_empty() {
                ans.push_str(" ");
            }
            ans.push_str(Self::solve_within_1000(thousand).as_str());
            ans.push_str(" Thousand");
        }
        if hundred > 0 {
            if !ans.is_empty() {
                ans.push_str(" ");
            }
            ans.push_str(Self::solve_within_1000(hundred).as_str());
        }
        return ans;
    }

    fn solve_within_1000(num: i32) -> String {
        if num == 0 {
            return String::new();
        }
        let mut ans = String::new();
        let hundred = num / 100;
        let within_hundred = num % 100;
        if hundred > 0 {
            ans.push_str(Self::DIGITS[hundred as usize]);
            ans.push_str(" ");
            ans.push_str("Hundred");
        }

        if !ans.is_empty() && within_hundred > 0 {
            ans.push_str(" ");
        }

        ans.push_str(Self::solve_within_100(within_hundred).as_str());
        return ans;
    }

    fn solve_within_100(num: i32) -> String {
        if num == 0 {
            return String::new();
        }

        let mut ans = String::new();
        let ten_digit = num / 10;
        let one_digit = num % 10;

        if ten_digit >= 2 {
            ans.push_str(Self::TENS_DIGITS[ten_digit as usize]);
            if one_digit > 0 {
                ans.push_str(" ");
                ans.push_str(Self::DIGITS[one_digit as usize]);
            }
        } else {
            ans.push_str(Self::DIGITS[num as usize]);
        }
        return ans;
    }
}
```
