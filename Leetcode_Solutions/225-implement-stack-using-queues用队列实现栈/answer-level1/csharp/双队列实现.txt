### 解题思路
用队列来实现栈的话，存储的方式不用改，只需要去更改取数据的逻辑。
比如说，我入栈的时候为 `[1, 2, 3]`, 那我可以把`[1, 2, 3]` 还是存储的队列里面，只是出栈的时候，我只需要把队尾的元素拿出来返回即可。
这样也就意味着，我取队列数据的时候， 需要有一个容器去存储出队的元素，等出队完了，再将存储的这些元素再次入队即可。
既然题目要求使用队列来实现，那用两个队列就可以。然后定义一个最后入队的元素的指针。

- push
 `push`操作，直接把元素入队即可。然后更新最后入队元素的指针。
- pop/top
 `pop` 和 `top`这两个操作时相似的。先把主队列中的元素全部存到临时队列中， 然后将临时队列中的前`n-1`个元素再次入队到主队列，那临时队列中剩下的最后一个元素就是我们要返回的元素。但是，再次过程中，要记得更新最后元素的指针；
- empty
 根据主队列的元素个数去返回就可以。

### 代码

```csharp
public class MyStack {

    Queue<int> _queue1;
    Queue<int> _queue2;
    int last = int.MinValue;

    /** Initialize your data structure here. */
    public MyStack()
    {
        _queue1 = new Queue<int>();
        _queue2 = new Queue<int>();
    }

    /** Push element x onto stack. */
    public void Push(int x)
    {
        _queue1.Enqueue(x);
        last = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    public int Pop()
    {
        if (_queue1.Count == 0)
        {
            last = int.MinValue;

            return last ;
        }

        if (_queue1.Count == 1)
        {
            last = int.MinValue;
            return _queue1.Dequeue();
        }
        _queue2.Clear();

        var count = _queue1.Count;

        for (int i = 0; i < count; i++)
        {
            _queue2.Enqueue(_queue1.Dequeue());
        }

        for (int i = 0; i < count - 1; i++)
        {
            if(i == count - 2)
            {
                last = _queue2.Peek();
            }
            _queue1.Enqueue(_queue2.Dequeue());
        }
        return _queue2.Dequeue();
    }

    /** Get the top element. */
    public int Top()
    {
        if (_queue1.Count == 0)
        {
            return last;
        }

        if (_queue1.Count == 1)
        {
            last = int.MinValue;
            return _queue1.Peek();
        }
        _queue2.Clear();

        var count = _queue1.Count;

        for (int i = 0; i < count; i++)
        {
            _queue2.Enqueue(_queue1.Dequeue());
        }

        for (int i = 0; i < count; i++)
        {
            if(i == count -1)
            {
                last = _queue2.Peek();
            }
            _queue1.Enqueue(_queue2.Dequeue());
        }
        

        return last;
    }

    /** Returns whether the stack is empty. */
    public bool Empty()
    {
        return _queue1.Count == 0;
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
实现的过程还可以再优化下，空了再弄。。