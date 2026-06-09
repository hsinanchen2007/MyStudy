### 解题思路
![image.png](https://pic.leetcode-cn.com/5c6223ee5ed2f46776c30c957118a475b7c54ba6c6adb455940e9217bf7d8b34-image.png)
### 代码

```rust
impl Solution {
    pub fn find_nth_digit(n: i32) -> i32 {
        let mut n: u32 = n as u32;
        let mut x: u32 = 0;
        let mut right: u32 = 0;

        // 确定数字区间
        while n > right {
            x += 1;
            n -= right;
            right = 10u32.pow(x - 1) * x * 9;
        }

        // 取出数字
        ((10u32.pow(x - 1) + (n - 1) / x) / 10u32.pow(if n % x > 0 { x - n % x } else { 0 }) % 10)
            as i32
    }
}

```