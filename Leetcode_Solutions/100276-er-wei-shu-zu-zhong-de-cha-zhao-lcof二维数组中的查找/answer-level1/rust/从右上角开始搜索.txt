### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn find_number_in2_d_array(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        
        if(matrix.len() == 0 || matrix[0].len() == 0){
            return false
        }
        
        let rows = matrix.len();
        let columns = matrix[0].len();
        let mut row:usize = 1;
        let mut column:usize = columns;
        
        while row <= rows && column > 0{
            if (*&matrix[row-1][column-1] == target){
                return true
            }else if *&matrix[row-1][column-1] < target{
                row+=1;
            }else if target < *&matrix[row-1][column-1]{
                column -= 1;
            }
        }
        false
    }
}
```