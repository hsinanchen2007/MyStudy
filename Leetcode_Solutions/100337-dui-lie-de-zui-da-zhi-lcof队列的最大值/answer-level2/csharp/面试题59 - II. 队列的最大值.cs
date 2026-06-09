### 解题思路
C# 使用单链表模拟双端队列

### 代码

```csharp
public class MaxQueue {
    Queue<int> queue = new Queue<int>();
    ListNode head;

    public MaxQueue()
    {
    }

    public int Max_value()
    {
        return head?.val ?? -1;
    }

    public void Push_back(int value)
    {
        queue.Enqueue(value);
        if (head == null)
        {
            head = new ListNode(value);
        }
        else
        {
            var current = head;
            // 使用链表模拟一个双端队列用于维护最大值
            if (head.val < value)
            {
                head = new ListNode(value);
                return;
            }
            // 用于从后向前压缩最大值队列
            while (current.next != null && current.next.val > value)
            {
                current = current.next;
            }
            current.next = new ListNode(value);
        }
    }

    public int Pop_front()
    {
        if (queue.Count == 0) return -1;
        var value = queue.Dequeue();
        if (head.val == value)
        {
            head = head.next;
        }
        return value;
    }
}

public class ListNode
{
    public int val;
    public ListNode next;

    public ListNode(int x) { val = x; }

    public ListNode Add(int nextValue)
        => this.next = new ListNode(nextValue);

    public override string ToString()
        => this.val.ToString();
}
/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.Max_value();
 * obj.Push_back(value);
 * int param_3 = obj.Pop_front();
 */
```