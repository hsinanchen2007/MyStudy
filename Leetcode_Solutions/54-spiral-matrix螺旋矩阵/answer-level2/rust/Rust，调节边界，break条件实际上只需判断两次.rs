看到不少人的代码判断四次条件，实际只要在下边和左边判断两次break条件即可，分别对应行数为奇和列数为奇的情况。
另外，注意为了避免usize（c++的size_t）向下溢出，右边界总是开，左边界闭：

代码如下，时空均超过100%rust:

```rust
/*
 * @lc app=leetcode.cn id=54 lang=rust
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
impl Solution {
    #[allow(clippy::needless_range_loop)]
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let mut res = vec![];
        if matrix.is_empty() {
            return res;
        }
        if matrix[0].is_empty() {
            return res;
        }
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut left = 0;
        let mut right = cols;
        let mut top = 0;
        let mut down = rows;
        while res.len() < cols * rows {
            for j in left..right {
                res.push(matrix[top][j]);
            }
            top += 1;
            for i in top..down {
                res.push(matrix[i][right-1]);
            }
            right -= 1;
            if down <= top {
                break;
            }
            for j in (left..right).rev() {
                res.push(matrix[down-1][j]);
            }
            down -= 1;
            if left >= right {
                break;
            }
            for i in (top..down).rev() {
                res.push(matrix[i][left]);
            }
            left += 1;
        }
        res
    }
}
// @lc code=end

struct Solution;

#[cfg(test)]
mod test {
    use super::*;
    use crate::utils::test_tools::nested_arr_to_vec;

    #[test]
    fn test_spiral_order() {
        assert_eq!(
            Solution::spiral_order(
                nested_arr_to_vec(
                    &[
                        &[ 1, 2, 3 ],
                        &[ 4, 5, 6 ],
                        &[ 7, 8, 9 ]
                    ]
                )),
                [1,2,3,6,9,8,7,4,5].to_vec()
        );
        assert_eq!(
            Solution::spiral_order(
                nested_arr_to_vec(
                    &[
                        &[1, 2, 3, 4],
                        &[5, 6, 7, 8],
                        &[9,10,11,12]
                    ]
                )),
                [1,2,3,4,8,12,11,10,9,5,6,7].to_vec()
        );
    }
}
```