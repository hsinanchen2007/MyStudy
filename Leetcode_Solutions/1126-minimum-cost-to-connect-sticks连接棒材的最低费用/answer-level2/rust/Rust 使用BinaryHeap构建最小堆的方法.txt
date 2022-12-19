
```rust 
use std::collections::{BinaryHeap};
use std::cmp::Reverse;
impl Solution {
    pub fn connect_sticks(sticks: Vec<i32>) -> i32 {
        let mut mh: BinaryHeap<_> = sticks.iter().map(|e|Reverse(*e)).collect();
        let mut min=0;
        loop{
            if let Some(m) = match (mh.pop(),mh.pop()) {
                (Some(Reverse(m)),Some(Reverse(n)))=> {mh.push(Reverse(m+n)); min+=(m+n);None},
                (Some(Reverse(m)),None) => Some(m),
                _ => {println!("rev");None}
            }
            {
                return min
            }
        }
    }
}
```

使用std::cmp::Reverse来将默认的大堆转换成小堆
