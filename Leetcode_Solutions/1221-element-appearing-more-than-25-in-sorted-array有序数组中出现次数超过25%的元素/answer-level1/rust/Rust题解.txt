```Rust
impl Solution {
    pub fn find_special_integer(arr: Vec<i32>) -> i32 {
        let mut l = 0;

        while let Ok(r) = arr.binary_search(&arr[l]) {
            if r - l >= arr.len() / 4 {
                return arr[l];
            }

            l = r + 1;
        }

        -1
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)
