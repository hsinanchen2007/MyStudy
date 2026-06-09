### 解题思路
此处撰写解题思路

### 代码

```rust
use std::collections::BinaryHeap;
use std::cmp::Reverse;
impl Solution {
    pub fn get_least_numbers(arr: Vec<i32>, k: i32) -> Vec<i32> {
        let mut heap = BinaryHeap::new();
        for v in arr {
            heap.push(Reverse(v));
        }
        let mut res:Vec<i32> = Vec::new();
        for i in 0..k{
            if let Some(Reverse(v)) = heap.pop() {
                res.push(v);
            }
        }
        res
    }
}
```