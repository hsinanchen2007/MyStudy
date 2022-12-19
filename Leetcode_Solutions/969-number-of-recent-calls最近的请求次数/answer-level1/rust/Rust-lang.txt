### 运行结果

![image.png](https://pic.leetcode-cn.com/2456cfbe21af781406ae9297e7eaaf51011a061baa95c46f55eade9232e2b837-image.png)

效率有点低

### 代码

```rust
use std::collections::vec_deque::VecDeque;

struct RecentCounter {
    ping_queue: VecDeque<i32>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RecentCounter {
    fn new() -> Self {
        let mut rc = RecentCounter {
            ping_queue: VecDeque::new(),
        };
        rc.ping_queue.reserve(10000);
        (rc)
    }
    
    fn ping(&mut self, t: i32) -> i32 {
        self.ping_queue.push_back(t);
        while let Some(x) = self.ping_queue.front() {
            if t - x > 3000 {
                self.ping_queue.pop_front();
            } else {
                break;
            }
        }
        (self.ping_queue.len() as i32)
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * let obj = RecentCounter::new();
 * let ret_1: i32 = obj.ping(t);
 */
```