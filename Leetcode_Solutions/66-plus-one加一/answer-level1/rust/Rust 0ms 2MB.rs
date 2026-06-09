### 解题思路
![image.png](https://pic.leetcode-cn.com/b595184ad9307e5b80efdf65d403da56b4c38d6682652f9da13a5a4bfd39e05d-image.png)


### 代码

```rust
impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut digits = digits;
        for i in (0..digits.len()).rev() {
            digits[i] += 1;
            digits[i] %= 10;
            if digits[i] != 0 {
                return digits;
            }
        }
        let mut res = vec![1];
        res.append(&mut digits);
        res
    }
}

```