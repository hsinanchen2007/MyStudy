### 解题思路
此处撰写解题思路

### 代码

```rust

impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n=matrix.len();
        for i in 0..n{
            for j in i+1..n{
                let tmp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=tmp;
            }
            matrix[i].reverse();
        }
    }
}
```