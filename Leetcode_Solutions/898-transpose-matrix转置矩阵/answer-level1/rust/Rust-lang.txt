### 运行结果

![image.png](https://pic.leetcode-cn.com/03c74800e79492b9e0d7bc7215881603de0c79325e09de9b8633082c09d5637a-image.png)

### 代码

```rust
impl Solution {
    pub fn transpose(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = vec![vec![0; a.len()]; a[0].len()];
        for i in 0..a[0].len() {
            for j in 0..a.len() {
                ans[i][j] = a[j][i];
            }
        }
        (ans)
    }
}
```