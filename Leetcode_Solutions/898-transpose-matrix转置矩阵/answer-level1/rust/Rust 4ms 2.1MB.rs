### 解题思路
![图片.png](https://pic.leetcode-cn.com/34366605ecb789f11b95881cbef1e5ca07a3346e282b1cc93b39cece7a5f17c6-%E5%9B%BE%E7%89%87.png)

### 代码

```rust
impl Solution {
    pub fn transpose(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        if a.len() == 0 {
            return vec![];
        }

        let h = a.len() as usize;
        let w = a[0].len() as usize;
        let mut res = Vec::new();

        for r in 0..w {
            let mut row = Vec::new();
            for c in 0..h {
                row.push(a[c][r]);
            }
            res.push(row);
        }
        res
    }
}

```