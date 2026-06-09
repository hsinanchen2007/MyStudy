找到对应坐标，填入res
烦人的转换
```rust
use std::iter;
impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let mut res = vec![];
        let n = matrix.len() as i32;
        if n == 0 {
            return res;
        }
        let m = matrix[0].len() as i32;
        let mut j = 0i32;
        while m -j > j && n-j>j{
            let row = iter::repeat(j).take(0.max(m-2*j) as usize)
                    .chain(j+1..n-j-1)
                    .chain(iter::repeat(n-j-1).take(0.max(m-2*j) as usize))
                    .chain((j+1..n-j-1).rev());
            //println!("{:?}",row.collect::<Vec<_>>());
            let col = (j..m-j)
                      .chain(iter::repeat(m-j-1).take(0.max(n-2*j-2) as usize))
                      .chain((j..m-j).rev())
                      .chain(iter::repeat(j).take(0.max(n-2*j-2) as usize));
            //println!("{:?}",col.collect::<Vec<_>>());
            for (p,q) in row.zip(col) {
                if res.len() < (m*n) as usize{
                    res.push(matrix[p as usize][q as usize]);
                }
            }
            j += 1;
        }
        res
    }
}
```
