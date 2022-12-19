### 代码

```rust
struct MinStack {
    stack_1: Vec<i32>,
    stack_2: Vec<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {

    /** initialize your data structure here. */
    fn new() -> Self {
        MinStack {
            stack_1: Vec::new(),
            stack_2: Vec::new(),
        }
    }
    
    fn push(&mut self, x: i32) {
        if self.stack_2.is_empty() {
            self.stack_1.push(x);
            self.stack_2.push(x);
        } else if self.stack_2[self.stack_2.len() - 1] >= x {
            self.stack_1.push(x);
            self.stack_2.push(x);
        } else {
            self.stack_1.push(x);
        }
    }
    
    fn pop(&mut self) {
        match self.stack_1.pop() {
            Some(val_1) => {
                if !self.stack_2.is_empty() && val_1 == self.stack_2[self.stack_2.len() - 1] {
                    self.stack_2.pop();
                }
            },

            None => {},
        }
    }
    
    fn top(&self) -> i32 {
        self.stack_1[self.stack_1.len() - 1]
    }
    
    fn min(&self) -> i32 {
        self.stack_2[self.stack_2.len() - 1]
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack::new();
 * obj.push(x);
 * obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: i32 = obj.min();
 */
```