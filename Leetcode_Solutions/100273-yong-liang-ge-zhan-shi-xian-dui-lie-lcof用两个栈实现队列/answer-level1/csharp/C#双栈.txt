### 解题思路
添加时都往一个栈添加，然后在出栈到另外一个栈。

### 代码

```csharp
public class CQueue {
    private Queue<int> currentQueue;
    private Queue<int> tempQueue;
    public CQueue() {
        this.currentQueue = new Queue<int>();
        this.tempQueue = new Queue<int>();
    }
    
    public void AppendTail(int value) {
        if(currentQueue.Count == 0)
        {
            currentQueue.Enqueue(value);
        }else{
            currentQueue.Enqueue(value);
            while(currentQueue.Count > 0)
            {
                tempQueue.Enqueue(currentQueue.Dequeue());
            }
            var temp = currentQueue;
            currentQueue = tempQueue;
            tempQueue = temp;
        }
    }
    
    public int DeleteHead() {
        if(currentQueue.Count == 0)
        {
            return -1;
        }
        return currentQueue.Dequeue();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.AppendTail(value);
 * int param_2 = obj.DeleteHead();
 */
```