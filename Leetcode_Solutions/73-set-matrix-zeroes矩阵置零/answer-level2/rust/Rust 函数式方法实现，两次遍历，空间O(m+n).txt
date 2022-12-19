```rust
use std::collections::HashSet;
impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let mut extra= Vec::new();
        matrix
            .iter()
            .enumerate()
            .for_each(|cur| 
                extra.append(
                    &mut cur
                    .1
                    .iter()
                    .enumerate()
                    .filter(|v|*v.1==0)
                    .map(|e|(cur.0,e.0))
                    .collect::<Vec<(usize,usize)>>()));
        extra
            .iter()
            .map(|e|e.0)
            .for_each(|i|
                (0..matrix[0]
                    .len())
                    .for_each(|j|
                        matrix[i][j]=0));
        extra
            .iter()
            .map(|e|e.1)
                .for_each(|j|
                    (0..matrix
                        .len())
                        .for_each(|i|
                            matrix[i][j]=0));
    }
}
```