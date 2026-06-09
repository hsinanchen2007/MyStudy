每个位置只遍历了1次...
```
impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        
        for i in 0..(n/2) {
            for j in i..(n - i - 1) {
                let mut p = i;
                let mut q = j;
                let mut prev = matrix[p][q];
                for _ in 0..3 {
                    let next = (((p * n + q + 1) * n) % (n * n + 1)) - 1;
                    let tmp = matrix[next / n][next % n];
                    matrix[next / n][next % n] = prev;
                    prev = tmp;
                    p = next / n;
                    q = next % n;
                }
                matrix[i][j] = prev;
            }
        }
    }
}
```
