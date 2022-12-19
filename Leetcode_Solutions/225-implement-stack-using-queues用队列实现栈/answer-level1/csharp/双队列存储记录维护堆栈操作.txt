### 解题思路
双队列维护。为啥我的内存消耗这么高。用一个临时队列帮助记录数据，储存数据。


### 代码

```csharp
public class MyStack {

    /** Initialize your data structure here. */
    Queue<int> que = new Queue<int>();
    Queue<int> tmpQue=new  Queue<int>();

    public MyStack() {
        
    }
    
    /** Push element x onto stack. */
    public void Push(int x) {
       this.que.Enqueue(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int Pop() {
        tmpQue.Clear();
                while(que.Count>1)
                {
                    tmpQue.Enqueue(que.Dequeue());
                }
          
                int res = que.Dequeue();

                while(tmpQue.Count>0)
                {
                    que.Enqueue(tmpQue.Dequeue());
                }
                 return res;          
    }
    
    /** Get the top element. */
    public int Top() {
          tmpQue.Clear();

                while(que.Count>1)
                {
                    tmpQue.Enqueue(que.Dequeue());
                }                    
               
                int res = que.Dequeue();

                while(tmpQue.Count>0)
                {
                    que.Enqueue(tmpQue.Dequeue());
                }
                que.Enqueue(res);
                return res;
    }
    
    /** Returns whether the stack is empty. */
    public bool Empty() {
        return que.Count == 0;
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