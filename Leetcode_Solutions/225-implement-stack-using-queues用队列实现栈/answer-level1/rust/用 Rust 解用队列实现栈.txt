## 解题思路
索引为 0 的元素是队列的前面。

定义 MyStack 结构体，里面只有一个变量 queue: VecDeque<i32>。

对结构体实现 Trait Default，这样在新建队列时，可以用 `Default::default()`，给变量 queue 一个默认值。相当于对结构体调用 `new()` 方法。
```Rust
MyStack{
    queue: VecDeque::new(),
}
```

当元素 x 入栈时，用到队列的 `push_back()` 方法，然后要把 x 前面的元素依次移到后面。记住索引为 0 的元素是队列的前面。

移除栈顶元素，调用队列的 `pop_front()` 方法即可。`unwrap()` 方法是把 Option<T> 里面的值是 Some(v) 时从里面移出来。

获取栈顶元素，调用队列的 `front()` 方法即可。

返回栈是否为空，调用队列的 `is_empty()` 方法即可。


## 完整代码
```Rust
use std::collections::VecDeque;
#[derive(Default)]
pub struct MyStack {
    queue: VecDeque<i32>,
}
impl MyStack {
    pub fn new() -> Self {
        Default::default()
    }
    pub fn push(&mut self, x: i32) {
        self.queue.push_back(x);
        for _ in 0..self.queue.len() - 1 {
            let val = self.queue.pop_front().unwrap();
            self.queue.push_back(val);
        }
    }
    pub fn pop(&mut self) -> i32 {
        self.queue.pop_front().unwrap()
    }
    pub fn top(&self) -> i32 {
        *self.queue.front().unwrap()
    }
    pub fn empty(&self) -> bool {
        self.queue.is_empty()
    }
}
```