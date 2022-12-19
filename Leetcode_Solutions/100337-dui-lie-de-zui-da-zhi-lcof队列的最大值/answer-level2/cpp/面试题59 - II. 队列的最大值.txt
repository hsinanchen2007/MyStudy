#### 方法一：暴力
**思路**

直接实现一个普通的队列，查询最大值时遍历计算。

```python [-Python 3]
import queue
class MaxQueue:

    def __init__(self):
        self.deque = queue.deque()

    def max_value(self) -> int:
        return max(self.deque) if self.deque else -1

    def push_back(self, value: int) -> None:
        self.deque.append(value)

    def pop_front(self) -> int:
        return self.deque.popleft() if self.deque else -1
```
```cpp [-C++]
class MaxQueue {
    int q[20000];
    int begin = 0, end = 0;
public:
    MaxQueue() {
    }
    
    int max_value() {
        int ans = -1;
        for (int i = begin; i != end; ++i)
            ans = max(ans, q[i]);
        return ans;
    }
    
    void push_back(int value) {
        q[end++] = value;
    }
    
    int pop_front() {
        if (begin == end)
            return -1;
        return q[begin++];
    }
};
```

**复杂度分析**

* 时间复杂度：$O(1)$（插入，删除），$O(n)$（求最大值）。
  插入与删除只需要普通的队列操作，为 $O(1)$，求最大值需要遍历当前的整个队列，最坏情况下为 $O(n)$。
* 空间复杂度：$O(n)$，需要用队列存储所有插入的元素。

#### 方法二：维护一个单调的双端队列
**思路**

本算法基于问题的一个重要性质：当一个元素进入队列的时候，它前面所有比它小的元素就不会再对答案产生影响。

举个例子，如果我们向队列中插入数字序列 `1 1 1 1 2`，那么在第一个数字 2 被插入后，数字 2 前面的所有数字 1 将不会对结果产生影响。因为按照队列的取出顺序，数字 2 只能在所有的数字 1 被取出之后才能被取出，因此如果数字 1 如果在队列中，那么数字 2 必然也在队列中，使得数字 1 对结果没有影响。

按照上面的思路，我们可以设计这样的方法：从队列尾部插入元素时，我们可以提前取出队列中所有比这个元素小的元素，使得队列中只保留对结果有影响的数字。这样的方法等价于要求维持队列单调递减，即要保证每个元素的前面都没有比它小的元素。

那么如何高效实现一个始终递减的队列呢？我们只需要在插入每一个元素 `value` 时，从队列尾部依次取出比当前元素 `value` 小的元素，直到遇到一个比当前元素大的元素 `value'` 即可。

  - 上面的过程保证了只要在元素 `value` 被插入之前队列递减，那么在 `value` 被插入之后队列依然递减。
  - 而队列的初始状态（空队列）符合单调递减的定义。
  - 由数学归纳法可知队列将会始终保持单调递减。

上面的过程需要从队列尾部取出元素，因此需要使用双端队列来实现。另外我们也需要一个辅助队列来记录所有被插入的值，以确定 `pop_front` 函数的返回值。

保证了队列单调递减后，求最大值时只需要直接取双端队列中的第一项即可。

```python [-Python 3]
import queue
class MaxQueue:

    def __init__(self):
        self.deque = queue.deque()
        self.queue = queue.Queue()

    def max_value(self) -> int:
        return self.deque[0] if self.deque else -1


    def push_back(self, value: int) -> None:
        while self.deque and self.deque[-1] < value:
            self.deque.pop()
        self.deque.append(value)
        self.queue.put(value)

    def pop_front(self) -> int:
        if not self.deque:
            return -1
        ans = self.queue.get()
        if ans == self.deque[0]:
            self.deque.popleft()
        return ans
```
```cpp [-C++]
class MaxQueue {
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if (d.empty())
            return -1;
        return d.front();
    }
    
    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        int ans = q.front();
        if (ans == d.front()) {
            d.pop_front();
        }
        q.pop();
        return ans;
    }
};
```

**复杂度分析**

* 时间复杂度：$O(1)$（插入，删除，求最大值）
  删除操作于求最大值操作显然只需要 $O(1)$ 的时间。
  而插入操作虽然看起来有循环，做一个插入操作时最多可能会有 $n$ 次出队操作。但要注意，由于每个数字只会出队一次，因此对于所有的 $n$ 个数字的插入过程，对应的所有出队操作也不会大于 $n$ 次。因此将出队的时间均摊到每个插入操作上，时间复杂度为 $O(1)$。
* 空间复杂度：$O(n)$，需要用队列存储所有插入的元素。
