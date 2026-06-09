### 解题思路

一个进栈队列, 一个出栈队列.

### 代码

```rust
use std::collections::VecDeque;

struct MyStack {
    a: VecDeque<i32>,
    b: VecDeque<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyStack {

    /** Initialize your data structure here. */
    fn new() -> Self {
        Self {
            a: VecDeque::new(),
            b: VecDeque::new(),
        }
    }
    
    /** Push element x onto stack. */
    fn push(&mut self, x: i32) {
        if self.a.is_empty() {
            self.b.push_back(x);
        } else {
            self.a.push_back(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    fn pop(&mut self) -> i32 {
        if self.a.is_empty() {
            for _ in 0..self.b.len()-1 {
                let x = self.b.pop_front().unwrap();
                self.a.push_back(x);
            }
            self.b.pop_front().unwrap()
        } else {
            for _ in 0..self.a.len()-1 {
                let x = self.a.pop_front().unwrap();
                self.b.push_back(x);
            }
            self.a.pop_front().unwrap()
        }
    }
    
    /** Get the top element. */
    fn top(&mut self) -> i32 {
        let x = self.pop();
        self.push(x);
        x
    }
    
    /** Returns whether the stack is empty. */
    fn empty(&self) -> bool {
        self.a.is_empty() && self.b.is_empty()
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * let obj = MyStack::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: bool = obj.empty();
 */
```