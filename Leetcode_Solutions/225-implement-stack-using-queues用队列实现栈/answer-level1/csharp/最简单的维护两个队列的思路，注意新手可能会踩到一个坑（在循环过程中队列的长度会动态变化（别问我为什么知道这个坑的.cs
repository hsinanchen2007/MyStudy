### 解题思路
维护两个队列和一个TOP值
需要pop的时候将队列一的前n-1个数转移到队列2（n为队列长度），剩余那个数即为所需的数。
### 代码

```csharp
public class MyStack {
    Queue<int> queue1,queue2;
    int top;
    /** Initialize your data structure here. */
    public MyStack() {
        queue1=new Queue<int>();
        queue2=new Queue<int>();
    }
    
    /** Push element x onto stack. */
    public void Push(int x) {
        queue1.Enqueue(x);
        top=x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int Pop() {
        //for (int i = 1; i < queue1.Count; i++)
        int count = queue1.Count;
        for (int i = 0; i < count - 1; i++)
        {
            //if (i == queue1.Count - 1)
            if (i == count - 2)
                top = queue1.Peek();
            queue2.Enqueue(queue1.Dequeue());
        }
        int x = queue1.Dequeue();
        Queue<int> temp;
        temp = queue1;
        queue1 = queue2;
        queue2 = temp;
        return x;
    }
    
    /** Get the top element. */
    public int Top() {
        return top;
    }
    
    /** Returns whether the stack is empty. */
    public bool Empty() {
        return queue1.Count > 0 ? false : true;      
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