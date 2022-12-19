![image.png](https://pic.leetcode-cn.com/7b4a28b764b524886ed5a87ed80a060b6565a1846b7462e53395c84071678325-image.png)
<br>

```Rust
impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let mut carry = 1;
        let mut nums:Vec<i32> = Vec::new();
        loop {
            let num = digits.pop();
            if num == None { break; }
            let new_num = num.unwrap() + carry;
            carry = new_num / 10;
            nums.insert(0, new_num % 10);
        }
        if carry > 0 { nums.insert(0, carry); }
        nums
    }
}
```

```Rust
impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let mut carry = 1;
        let len = digits.len();
        for i in 0..len {
            let _i = len - 1 - i;
            let num = digits[_i] + carry;
            carry = num / 10;
            digits[_i] = num % 10;
        }
        if carry > 0 { digits.insert(0, carry); }
        digits
    }
}
```