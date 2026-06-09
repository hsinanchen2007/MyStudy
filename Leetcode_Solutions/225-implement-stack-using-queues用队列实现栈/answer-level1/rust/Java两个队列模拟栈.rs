### 解题思路
此处撰写解题思路

### 代码

```java
class MyStack {
    private Queue<Integer> q1 = new LinkedList<>();
    private Queue<Integer> q2 = new LinkedList<>();
    private int top;
    /** Initialize your data structure here. */
    public MyStack() {

    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        q1.add(x);
        top = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        while(q1.size() > 1){
            top = q1.poll();
            q2.add(top);
        }
        int tmp = q1.remove();
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;
        return tmp;
        
    }
    
    /** Get the top element. */
    public int top() {
        return top;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q1.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
```
```
struct MyStack {
    q1: Vec<i32>,
    q2: Vec<i32>,
    top: i32 
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyStack {

    /** Initialize your data structure here. */
    fn new() -> Self {
        MyStack{
            q1 : Vec::new(),
            q2 : Vec::new(),
            top : 0
        }
    }
    
    /** Push element x onto stack. */
    fn push(&mut self, x: i32) {
        self.q1.push(x);
        self.top = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    fn pop(&mut self) -> i32 {
        while self.q1.len() > 1{
            self.top = self.q1.remove(0);
            self.q2.push(self.top)
        }
        let tmp: i32 = self.q1.remove(0);
        let temp = self.q1.clone();
        self.q1 = self.q2.clone();
        self.q2 = temp;
        return tmp;
    }
    
    /** Get the top element. */
    fn top(&self) -> i32 {
        return self.top;
    }
    
    /** Returns whether the stack is empty. */
    fn empty(&self) -> bool {
        return self.q1.is_empty();
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