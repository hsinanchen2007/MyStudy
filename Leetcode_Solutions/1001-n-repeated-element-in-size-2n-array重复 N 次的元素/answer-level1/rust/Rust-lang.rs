### 运行结果

![image.png](https://pic.leetcode-cn.com/26d97dba2cce8e27e58dcde16266d51f8e6330299f731ba568fb10ba0761a64c-image.png)

### 代码

```rust
impl Solution {
    pub fn repeated_n_times(a: Vec<i32>) -> i32 {
        let len = a.len();
        for i in 0..(len - 2) {
            if a[i] == a[i + 1] || a[i] == a[i + 2] {
                return a[i];
            }
        }
        a[len - 1]
    }
}

```