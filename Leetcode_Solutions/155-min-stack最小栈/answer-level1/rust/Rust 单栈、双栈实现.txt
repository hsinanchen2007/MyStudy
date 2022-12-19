双栈，一个作为数据栈，一个存储当前的最小值
```rust
struct MinStack {
    stack: Vec<i32>,
    min_stack: Vec<i32>,
}

impl MinStack {
    /** initialize your data structure here. */
    fn new() -> Self {
        Self{
            stack: Vec::new(),
            min_stack: Vec::new(),
        }
    }
    
    fn push(&mut self, x: i32) {
        if self.stack.is_empty() || x <= self.get_min()  {
            self.stack.push(x);
            self.min_stack.push(x);
        } else {
            self.stack.push(x);
        }
    }
    
    fn pop(&mut self) {
        if let Some(v) = self.stack.pop(){
            if v == self.get_min() {
                self.min_stack.pop();
            }
        }
    }
    
    fn top(&self) -> i32 {
        if let Some (v) = self.stack.last() {
            *v
        } else {
            std::i32::MAX
        }
    }
    
    fn get_min(&self) -> i32 {
        if let Some (v) = self.min_stack.last() {
            *v
        } else {
            std::i32::MAX
        }
    }
}
```

单个栈，在最小值改变的时候把最小值也压入栈中
```rust
struct MinStack {
    stack: Vec<i32>,
    min: i32,
}

impl MinStack {
    fn new() -> Self {
        Self{
            stack: Vec::new(),
            min: std::i32::MAX,
        }
    }
    
    fn push(&mut self, x: i32) {
        if self.stack.is_empty() {
            self.min = x;
        } else if x <= self.min  {
            self.stack.push(self.min);
            self.min = x;
        } 
        self.stack.push(x);
    }
    
    fn pop(&mut self) {
        if let Some(v) = self.stack.pop(){
            if v == self.min {
                self.min = self.stack.pop().unwrap_or(std::i32::MAX);
            }
        }
    }
    
    fn top(&self) -> i32 {
        if let Some (v) = self.stack.last() {
            *v
        } else {
            std::i32::MAX
        }
    }
    
    fn get_min(&self) -> i32 {
        self.min
    }
}
```