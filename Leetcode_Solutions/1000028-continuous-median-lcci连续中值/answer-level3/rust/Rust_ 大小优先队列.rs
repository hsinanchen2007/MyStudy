维护2个优先队列，大堆存小的一半数据，小堆存大的一半数据，数据流到来后，维持两堆数量差不超过1，取中位数时，拿它们的堆顶即可。

```rust
use std::collections::BinaryHeap;
use std::cmp::Reverse;
struct MedianFinder {
    /// larger half
    min_heap: BinaryHeap<Reverse<i32>>,
    /// smaller half
    max_heap: BinaryHeap<i32>,
    size: usize
}


impl MedianFinder {
    
    fn new() -> Self {
        MedianFinder {
            min_heap: BinaryHeap::new(),
            max_heap: BinaryHeap::new(),
            size: 0
        }
    }

    fn add_num(&mut self, num: i32) {
        if self.size == 0 {
            self.min_heap.push(Reverse(num));
            self.size += 1;
            return;
        }

        if self.min_heap.peek().unwrap().0 > num {
            self.max_heap.push(num);
            while self.max_heap.len() > self.min_heap.len() {
                self.min_heap.push(Reverse(self.max_heap.pop().unwrap()));
            }
        } else {
            self.min_heap.push(Reverse(num));
            while self.min_heap.len() > self.max_heap.len() + 1 {
                self.max_heap.push(self.min_heap.pop().unwrap().0);
            }
        }
        self.size += 1;
    }

    fn find_median(&self) -> f64 {
        if self.size == 0 {
            return 0.0;
        }
        return if self.size % 2 == 0 {
            0.5 * (self.min_heap.peek().unwrap().0 + *self.max_heap.peek().unwrap()) as f64
        } else {
            self.min_heap.peek().unwrap().0 as f64
        }
    }
}
```