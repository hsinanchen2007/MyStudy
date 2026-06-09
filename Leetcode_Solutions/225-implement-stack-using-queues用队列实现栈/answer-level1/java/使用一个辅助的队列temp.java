### 解题思路
思路1：在每次进行push的时候，都使用辅助的队列。使的一个队列里面的元素可以全部按照栈里面先进后出的顺序进行储存；
1. 插入元素1
    queue：1
    temp：null
2. 插入元素2
    queue：1             queue：null
    temp：2     进行转化   temp：2 <- 1(尾部)
3. 插入元素3
    queue：3                        queue：3 <- 2 <- 1(尾部)
    temp：2 <- 1(尾部)     进行转化   temp：null

插入元素的时候，进行上面的重复的操作
pop(),top()的时候操作那个不为空的队列就可以了

```
class MyStack {

Queue<Integer> queue;
    Queue<Integer> temp;
    /** Initialize your data structure here. */
    public MyStack() {
        queue = new LinkedList<>();
        temp = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        if(queue.isEmpty()){
            queue.add(x);
            while(!temp.isEmpty()){
                queue.add(temp.poll());
            }
        }
        else{
            temp.add(x);
            while(!queue.isEmpty()){
                temp.add(queue.poll());
            }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(queue.isEmpty()){
            return temp.poll();
        }
        else{
            return queue.poll();
        }

    }
    
    /** Get the top element. */
    public int top() {
        if(queue.isEmpty()){
            return temp.peek();
        }
        else{
            return queue.peek();
        }
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return temp.isEmpty() && queue.isEmpty();
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

思路2：在思路1的基础上进行了优化
一直使用push的时候，操作和思路1是一样的；
但是，在某一个队列中只有一个元素的时候，如果要出栈，直接将size()为1的进行poll()就可以了，这样简化了一边push,一边pop()是的操作，不用在进行两个队列之间的相互的转化

### 代码

```java
class MyStack {
    Queue<Integer> queue;
    Queue<Integer> temp;
    /** Initialize your data structure here. */
    public MyStack() {
        queue = new LinkedList<>();
        temp = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        if(queue.isEmpty()){
            queue.add(x);
        }
        else if(temp.isEmpty()){
            temp.add(x);
        }
        else{
            while(!queue.isEmpty()){
                temp.add(queue.poll());
            }
            queue.add(x);
            // System.out.println(queue.peek());
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(temp.size() == 1){
            return temp.poll();
        }
        else if(queue.size() == 1){
            return queue.poll();
        }
        else{
            return temp.poll();
        }
    }
    
    /** Get the top element. */
    public int top() {
        if(temp.size() == 1){
            return temp.peek();
        }
        else if(queue.size() == 1){
            return queue.peek();
        }
        else{
            return temp.peek();
        }
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return temp.isEmpty() && queue.isEmpty();
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