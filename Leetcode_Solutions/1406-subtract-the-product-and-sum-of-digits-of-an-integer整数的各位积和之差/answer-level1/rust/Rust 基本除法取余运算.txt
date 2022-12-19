### 提交结果
![image.png](https://pic.leetcode-cn.com/e541d4d216581baaed8a61e2179a3192d4f80d022e337a230c5961a612247411-image.png)

（手动安利Rust，效率高，内存占用小）

### 解题思路

基本的除十取余运算。

还可以通过转成字符串来计算，但此题数字较小，没必要用这种方法。

### 解题代码

```rust
impl Solution {
    pub fn subtract_product_and_sum(n: i32) -> i32 {
        let mut num = n;
        let mut pro = 1i32;
        let mut sum = 0i32;

        while 0 != num {
            let temp = num % 10;
            pro *= temp;
            sum += temp;
            num /= 10;
        }

        (pro - sum)
    }
}
```
