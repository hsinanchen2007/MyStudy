### 解题思路
此处撰写解题思路
1、使用两个队列来存储数据，始终保持一个队列为空，另一个队列不为空
2、不同的操作，其队列的使用情况
    1. Push
       插入元素时，选取不为空的那个队列进行入队操作，如果都为空，则默认选择第一个
    2. Pop
       弹出顶部元素时，将不为空的队列逐个弹出，然后入队到另一个空的队列，并判断当前队列的元素，如果数量为1，则表面到了队列的最后一个元素，相当于栈顶，然后获取当前值，直接返回，那么这个元素将不会再入队到另一个队列中，也即实现了弹出操作
    3. Top
       和Poo操作很像，只不过在获取队列底部元素后，并不直接返回，而是继续将此元素入队到另一个队列
    4. Empty
       判断两个对象的元素是否都为空，不为空则返回false，否则返回true 

### 代码

```csharp
public class MyStack {

    private Queue<int> queue1;
    private Queue<int> queue2;

    public MyStack() {
        queue1 = new Queue<int>();
        queue2 = new Queue<int>();
    }
    
    /** Push element x onto stack. */
    public void Push(int x) {
        if(queue1.Count!=0) {
            queue1.Enqueue(x);
        }else {
            queue2.Enqueue(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int Pop() {
        int result =0;
        if(queue1.Count!=0) {
            while(queue1.Count!=0) {
                if(queue1.Count==1)
                    return queue1.Dequeue();
                queue2.Enqueue(queue1.Dequeue());
            }
        }else {
            while(queue2.Count!=0) {
                if(queue2.Count==1)
                    return queue2.Dequeue();
                queue1.Enqueue(queue2.Dequeue());
            }
        }
        return result;
    }
    
    /** Get the top element. */
    public int Top() {
        int result = 0;
        if(queue1.Count!=0) {
            while(queue1.Count!=0) {
                if(queue1.Count==1)
                    result = queue1.Peek();
                queue2.Enqueue(queue1.Dequeue());
            }
        }else {
            while(queue2.Count!=0) {
                if(queue2.Count==1)
                    result = queue2.Peek();
                queue1.Enqueue(queue2.Dequeue());
            }
        }
        return result;
    }
    
    /** Returns whether the stack is empty. */
    public bool Empty() {
        if(queue1.Count==0 && queue2.Count==0)
            return true;
        else
            return false;
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