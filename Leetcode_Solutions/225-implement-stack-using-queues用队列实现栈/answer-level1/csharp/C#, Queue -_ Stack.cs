### 解题思路
Push & Empty & Top,时间复杂度O(1)
Pop,时间复杂度O(n)

push(0)
push(1)
push(2)
=> queue 入队列方向-> 2,1,0 ->出队列方向

pop()时，期望输出2。
循环q.Count-1次，将queue元素出队&重新入队，获得入队列方向-> 1,0,2 ->出队列方向。
此时出队，即获得目标元素。


### 代码

```csharp
public class MyStack {
    private Queue<int> q;
    private int top;
    /** Initialize your data structure here. */
    public MyStack() {
        q = new Queue<int>();
    }
    
    /** Push element x onto stack. */
    public void Push(int x) {
        q.Enqueue(x);
        top = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int Pop() {
        for(var i = 1; i < q.Count; i ++)
        {
            var item = q.Dequeue();
            q.Enqueue(item);
            if (i == q.Count - 1)
                top = item;
        }
        return q.Dequeue();
    }
    
    /** Get the top element. */
    public int Top() {
        return this.top;
    }
    
    /** Returns whether the stack is empty. */
    public bool Empty() {
        return q.Count == 0;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.Push(x);
 * int param_2 = obj.Pop();
 * int param_3 = obj.Top();
 * bool param_4 = obj.Empty();
 */
```