一个队列只负责Push，另一个负责Pop

```
public class MyQueue {
    private Stack<int> s1;
    private Stack<int> s2;
    /** Initialize your data structure here. */
    public MyQueue() {
        s1 = new Stack<int>();
        s2 = new Stack<int>();
    }
    
    /** Push element x to the back of queue. */
    public void Push(int x) {
        s1.Push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int Pop() {
        if(s2.Count!=0)
        {
            return s2.Pop();
        }
        while(s1.Count>0)
        {
            s2.Push(s1.Pop());
        }
        if(s2.Count>0)
            return s2.Pop();
        throw new InvalidOperationException("Queue is empty");
    }
    
    /** Get the front element. */
    public int Peek() {
        if(s2.Count!=0)
        {
            return s2.Peek();
        }
        while(s1.Count>0)
        {
            s2.Push(s1.Pop());
        }
        return s2.Peek();
    }
    
    /** Returns whether the queue is empty. */
    public bool Empty() {
        return s1.Count==0 && s2.Count==0;
    }
}
```
