执行结果：
通过
显示详情
执行用时 :
0 ms
, 在所有 Rust 提交中击败了
100.00%
的用户
内存消耗 :
2.1 MB
, 在所有 Rust 提交中击败了
100.00%
的用户
```
    impl Solution {
        pub fn flip_and_invert_image(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
            let ret: Vec<Vec<i32>> = a.iter().map(|mut row| -> Vec<i32> {
                let mut new_row: Vec<i32> = row.iter().map(|x| -> i32 {
                    let new_x = if let 0 = x {
                        1
                    } else { 0 };
                    new_x
                }).collect();
                new_row.reverse();
                new_row
            }).collect();
            ret
        }
    }
```
