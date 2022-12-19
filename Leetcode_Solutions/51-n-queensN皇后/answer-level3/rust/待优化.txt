执行用时 :
596 ms
, 在所有 rust 提交中击败了
11.11%
的用户

...
执行用时 :
296 ms
, 在所有 rust 提交中击败了
11.11%
的用户

```
impl Solution {
    fn trans_to_ans(matrix: &mut Vec<Vec<u8>>) -> Vec<String> {
        let mut copy = matrix.clone();
        for i in 0..copy.len() {
            for j in 0..copy.len() {
                if copy[i][j] == b'1' {
                    copy[i][j] = b'.';
                }
            }
        }
        copy.into_iter().map(|row_vec| unsafe {String::from_utf8_unchecked(row_vec)} ).collect()
    }
    fn turn_off(matrix: &mut Vec<Vec<u8>>, m: usize, n: usize, poss: &mut Vec<usize>) {
        /*
        for i in 0..matrix.len() {
            for j in 0..matrix.len() {
                if  matrix[i][j] == b'.' && (
                        i == m || j == n || (i + j) == (m + n) 
                        || ((m >= n) && (i >= j) && (m - n == i - j)) 
                        || ((m < n) && (i < j) && (n - m == j - i))
                        )
                     {
                    matrix[i][j] = b'1';
                    poss.push(i *  matrix.len() + j);
                }
            }
        }
        */
        for i in 0..matrix.len() {
            if matrix[m][i] == b'.' {
                matrix[m][i] = b'1';
                poss.push(m *  matrix.len() + i);
            }
        }
        for i in 0..matrix.len() {
            if matrix[i][n] == b'.' {
                matrix[i][n] = b'1';
                poss.push(i *  matrix.len() + n);
            }
        }
        let mut tmp_m = m;
        let mut tmp_n = n;
        while tmp_m < matrix.len() - 1 && tmp_n > 0 {
            tmp_m += 1;
            tmp_n -= 1;
            if matrix[tmp_m][tmp_n] == b'.' {
                matrix[tmp_m][tmp_n] = b'1';
                poss.push(tmp_m *  matrix.len() + tmp_n);
            }
        }
        tmp_m = m;
        tmp_n = n;
        while tmp_m > 0 && tmp_n < matrix.len() - 1 {
            tmp_m -= 1;
            tmp_n += 1;
            if matrix[tmp_m][tmp_n] == b'.' {
                matrix[tmp_m][tmp_n] = b'1';
                poss.push(tmp_m *  matrix.len() + tmp_n);
            }
        }

        tmp_m = m;
        tmp_n = n;
        while tmp_m > 0 && tmp_n > 0 {
            tmp_m -= 1;
            tmp_n -= 1;
            if matrix[tmp_m][tmp_n] == b'.' {
                matrix[tmp_m][tmp_n] = b'1';
                poss.push(tmp_m *  matrix.len() + tmp_n);
            }
        }
        tmp_m = m;
        tmp_n = n;
        while tmp_m < matrix.len() - 1 && tmp_n < matrix.len() - 1 {
            tmp_m += 1;
            tmp_n += 1;
            if matrix[tmp_m][tmp_n] == b'.' {
                matrix[tmp_m][tmp_n] = b'1';
                poss.push(tmp_m *  matrix.len() + tmp_n);
            }
        }
    }
    fn turn_on(matrix: &mut Vec<Vec<u8>>, poss: & Vec<usize>) {
        let n = matrix.len();
        for idx in 0..poss.len() {
            matrix[poss[idx] / n][poss[idx] % n] = b'.';
        }
    }
    fn backtrace(matrix: &mut Vec<Vec<u8>>, n: usize, start: usize, q_nums: i32, ans: &mut Vec<Vec<String>>) {
        if q_nums as usize >= n {
            ans.push(Self::trans_to_ans(matrix));
            return;
        }

        for i in (start / n)..n {
            for j in 0..n {
                if matrix[i][j] == b'.' {
                    matrix[i][j] = b'Q';
                    let mut poss: Vec<usize> = vec![];
                    Self::turn_off(matrix, i, j, &mut poss);
                    Self::backtrace(matrix, n, (i + 1) * n, q_nums + 1, ans); 
                    Self::turn_on(matrix, &poss);
                    matrix[i][j] = b'.';
                }
            }   
        }
    }
    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        let mut matrix = vec![vec![b'.'; n as usize]; n as usize];
        let mut ans: Vec<Vec<String>> = vec![];
        if n == 0 {
           return ans;
        }
        Self::backtrace(&mut matrix, n as usize, 0, 0, &mut ans);
        ans
    }
}
```
