这道题相对简单，基于数组来做即可，这里提供一个Rust版本的参考解法。

```rust
use std::cell::RefCell;
use std::cmp;

#[derive(Debug, PartialEq, Eq)]
struct CustomStack {
    pub val: RefCell<Vec<i32>>,
    pub max_size: i32,
}


impl CustomStack {
    fn new(max_size: i32) -> Self {
        CustomStack {
            val: RefCell::new(Vec::new()),
            max_size,
        }
    }

    fn push(&self, x: i32) {
        let t= &self.val;
        let mut vec = t.borrow_mut();

        if vec.len() < self.max_size as usize {
            vec.push(x);
        }
    }

    fn pop(&self) -> i32 {
        match &self.val.borrow_mut().pop() {
            Some(v) => *v,
            None => -1,
        }
    }

    fn increment(&self, k: i32, val: i32) {
        let t= &self.val;
        let mut vec = t.borrow_mut();
        for i in 0..cmp::min(k as usize, vec.len()) {
            vec[i] += val;
        }
    }
}
```
