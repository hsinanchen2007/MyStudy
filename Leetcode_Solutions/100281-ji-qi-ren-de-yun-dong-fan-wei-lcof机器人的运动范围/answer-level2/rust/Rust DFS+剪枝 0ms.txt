```
impl Solution {
    pub fn moving_count(m: i32, n: i32, k: i32) -> i32 {
        let (mut count, mut matrix) = (0, vec![vec![0;n as usize];m as usize]);

        Self::find_every_blank(m ,n, k, 0, 0, &mut count, &mut matrix);

        count
    }

    pub fn find_every_blank(m: i32, n: i32, k: i32, row: i32, col: i32, count: &mut i32, matrix: &mut Vec<Vec<i32>>) {
        // println!("row {} col {} count {} matrix {:?}", row, col, count, matrix);
        if !Self::is_valid_blank(m, n, k, row, col) { return }
        let neighbors = vec![(row,col-1), (row,col+1), (row+1,col), (row-1,col)];
        
        if matrix[row as usize][col as usize] == 0 {
            *count += 1;
            matrix[row as usize][col as usize] = 1;
        }
        else {
            return;
        }

        for neighbor in neighbors {
            Self::find_every_blank(m ,n, k, neighbor.0, neighbor.1, count, matrix);
        }
    }

    pub fn is_valid_blank(m: i32, n: i32, k: i32, row: i32, col: i32) -> bool {
        if row < 0 || col < 0 || row >= m || col >= n { return false; }
        if Self::get_digits_sum(row) + Self::get_digits_sum(col) > k { return false; }
        true
    }

    pub fn get_digits_sum(mut n: i32) -> i32 {
        let mut sum = 0;
        while n > 0 {
            sum += n % 10;
            n /= 10; 
        }
        sum
    }
}
```
