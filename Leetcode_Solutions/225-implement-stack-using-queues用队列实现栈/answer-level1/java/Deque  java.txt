### 解题思路
用一个双端队列实现栈。思路：数据进入队列后，就对数据进行“反转”操作，使得数据仿佛压入栈中。比如： 进入队列顺序为1，2 ，执行push()操作后在队列中的顺序为2,1；此时3入队，队列初始状态为2,1,3，执行push()操作后在队列中的顺序3,2,1。经过push()处理后，出栈时直接pop()即可。
Deque 是 Double ended queue (双端队列) , 继承自 Queue,直接实现了它的类有ArrayDeque, LinkedBlockingDeque, LinkedList 等。
addLast(e)  将指定元素插入此双端队列的末尾。可能无法插入元素，而只是抛出一个异常。通常首选 offerLast(E) 方法。 
offerLast(e) 将指定的元素插入此双端队列的末尾。当使用有容量限制的双端队列时，优于addLast(E) 方法。
removeFirst() 获取并移除此双端队列第一个元素。此方法与 pollFirst 唯一的不同在于：如果此双端队列为空，它将抛出一个异常
pollFirst() 获取并移除此双端队列的第一个元素；如果此双端队列为空，则返回 null。
getFirst() 获取，但不移除此双端队列的第一个元素。 此方法与peekFirst 唯一的不同在于：如果此双端队列为空，它将抛出一个异常。
peekFirst() 获取，但不移除此双端队列的第一个元素；如果此双端队列为空，则返回 null。


### 代码

```java
class MyStack {
   Deque<Integer> s;
    /** Initialize your data structure here. */
    public MyStack() {
           s=new ArrayDeque<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        s.addLast(x);
        int len=s.size();
        while(len>1){
            s.addLast(s.pollFirst());
            len--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
       return s.pollFirst();
    }
    
    /** Get the top element. */
    public int top() {
        
        return s.peekFirst();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return s.isEmpty();
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