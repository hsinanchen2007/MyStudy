### 解题思路
这一道题的难点有二：
1. 读懂题目
2. 时间复杂度都是O(1)。

还有一个问题，就是由于 C# 在 initialize `array` 的时候，要求提供size，可是queue的size是不定的，所以需要用`List<int>`来储存值。

### 代码

```csharp
public class MaxQueue {
    private List<int> maxQueue;

    public MaxQueue() {
        this.maxQueue = new List<int>();
    }
    
    public int Max_value() {
        if (this.maxQueue.Count == 0) { return -1; }

        return this.maxQueue.Max();
    }
    
    public void Push_back(int value) {
        this.maxQueue.Add(value);
    }
    
    public int Pop_front() {
        if (this.maxQueue.Count == 0) { return -1; }

        int front = this.maxQueue[0];
        this.maxQueue = this.maxQueue.Skip(1).ToList();

        return front;
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.Max_value();
 * obj.Push_back(value);
 * int param_3 = obj.Pop_front();
 */
```