执行用时 :
616 ms
, 在所有 Rust 提交中击败了
27.27%
的用户
```
pub fn largest_rectangle_area(heights: Vec<i32>) -> i32 {
        let len = heights.len();
        let mut max = 0;
        for i in 0..len {
            let mut min = std::i32::MAX;
            for j in i..len {
               // max = std::cmp::max(max, heights[i..=j].iter().min().cloned().unwrap() * (j - i + 1) as i32);
               min = std::cmp::min(min, heights[j]);
               max = std::cmp::max(max, min * (j - i + 1) as i32);
            }
        }
        max
    }
```
