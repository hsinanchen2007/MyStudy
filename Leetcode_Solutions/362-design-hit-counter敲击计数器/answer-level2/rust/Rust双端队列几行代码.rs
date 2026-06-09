这道题就是个双端队列的裸题，每次Hit就往队尾插一条记录。每次get就从前开始删除离当前大于等于300的。结果就是队列长度

0ms

```rust
use std::collections::VecDeque;

struct HitCounter {
    dq: VecDeque<i32>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl HitCounter {

    /** Initialize your data structure here. */
    fn new() -> Self {
        Self{
            dq: VecDeque::new(),
        }
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    fn hit(&mut self, timestamp: i32) {
        self.dq.push_back(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    fn get_hits(&mut self, timestamp: i32) -> i32 {
        while let Some(&v) = self.dq.front() {
            if timestamp - v >= 300 {
                 self.dq.pop_front();
            } else {
                break;
            }
        }
        self.dq.len() as i32
    }
}
```