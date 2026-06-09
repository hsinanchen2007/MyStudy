### 运行结果

![image.png](https://pic.leetcode-cn.com/2e52162814972f1b47d48bca4a3f772babe8761f25ac399e67f17f2c4f452daf-image.png)

### 代码

```rust
impl Solution {
    pub fn smallest_range_i(a: Vec<i32>, k: i32) -> i32 {
        let x = a.iter().max().unwrap();
        let y = a.iter().min().unwrap();
        let ans = x - y - 2 * k;
        if ans <= 0 { // 小于0必然有0为最小差值
            return 0;
        } else {
            return ans;
        }
    }
}
```