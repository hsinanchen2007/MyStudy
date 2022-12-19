####  方法一：数组或列表
我们可以用数组或列表来记录所有传入的值。然后从中取出对应的元素来计算平均值。
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMzQ2LzM0Nl9hcnJheS5wbmc?x-oss-process=image/format,png)
**算法：**
- 我们初始化 `queue` 来存储数据流的数据和移动窗口 `n` 的大小。
- 每次调用 `next(val)`，首先将 `val` 添加到 `queue` 中，然后我们从 `queue` 取最后 `n` 个元素计算平均值。

```python [solution1-Python]
class MovingAverage:
    def __init__(self, size: int):
        self.size = size
        self.queue = []
        
    def next(self, val: int) -> float:
        size, queue = self.size, self.queue
        queue.append(val)
        # calculate the sum of the moving window
        window_sum = sum(queue[-size:])

        return window_sum / min(len(queue), size)
```

```java [solution1-Java]
class MovingAverage {
  int size;
  List queue = new ArrayList<Integer>();
  public MovingAverage(int size) {
    this.size = size;
  }
​
  public double next(int val) {
    queue.add(val);
    // calculate the sum of the moving window
    int windowSum = 0;
    for(int i = Math.max(0, queue.size() - size); i < queue.size(); ++i)
      windowSum += (int)queue.get(i);
​
    return windowSum * 1.0 / Math.min(queue.size(), size);
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$。其中 $N$ 是移动窗口的大小，每次调用 `next(val)`，我们需要从 `queue ` 中检索 $N$ 个元素。
* 空间复杂度：$\mathcal{O}(M)$，是 `queue` 的大小。


####  方法二：双端队列
我们可以比方法一使用更优的时间复杂度和空间复杂度。

我们会注意到并不需要存储数据流中的所有值，只需要数据流中的最后 `n` 个值。

根据移动窗口的定义，在每个步骤中，我们向窗口添加一个新元素，同时从窗口中删除第一个元素。这里，我们可以应用一种称为双端队列的数据结构（`deque`）来实现移动窗口，它在两端删除或添加元素将具有常数的时间复杂度（$\mathcal{O}(1)$）；使用双端队列，我们可以将空间复杂度降低到 $\mathcal{O}(N)$，其中 $N$ 是移动窗口的大小。
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMzQ2LzM0Nl9kZXF1ZS5wbmc?x-oss-process=image/format,png)

其次，为了计算移动窗口元素的总和 `sum`，我们不需要遍历窗口的全部元素。

我们可以保留前一个移动窗口的总和 `sum`，然后为了得到新的移动窗口的总和，我们只需要 `sum+=new_val,sum-=first_val`，这样就可以得到新的总和，其中 `new_val` 为添加的值，`first_val` 为原移动窗口中的第一个值，这样可以将时间复杂度降低到常数。

**算法：**
下面是 Python 中 `deque` 的定义。我们在其他编程语言（如 Java）中也有类似的 `deque` 实现。

Deques 是堆栈和队列的泛化（名称读作 `deck`，是双端队列的缩写）。Deques 支持线程安全，可以在两端在时间复杂度为 $O(1)$ 进行添加和删除元素。

根据前面说的，我们用 `deque` 替换队列，并添加一个新的变量 `window_sum`，在常数时间内计算移动窗口的和。

```python [solution2-Python]
from collections import deque
class MovingAverage:
    def __init__(self, size: int):
        self.size = size
        self.queue = deque()
        # number of elements seen so far
        self.window_sum = 0
        self.count = 0
    
    def next(self, val: int) -> float:
        self.count += 1
        # calculate the new sum by shifting the window
        self.queue.append(val)
        tail = self.queue.popleft() if self.count > self.size else 0
        
        self.window_sum = self.window_sum - tail + val
        
        return self.window_sum / min(self.size, self.count)
```

```java [solution2-Java]
class MovingAverage {
  int size, windowSum = 0, count = 0;
  Deque queue = new ArrayDeque<Integer>();
    
  public MovingAverage(int size) {
    this.size = size;
  }

  public double next(int val) {
    ++count;
    // calculate the new sum by shifting the window
    queue.add(val);
    int tail = count > size ? (int)queue.poll() : 0;
     
    windowSum = windowSum - tail + val;

    return windowSum * 1.0 / Math.min(size, count);
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(1)$。
* 空间复杂度：$\mathcal{O}(N)$，移动窗口的大小。


####  方法三：基于数组的循环队列
除了 `deque` 之外，还可以应用另一种有趣的数据结构，称为循环队列 `circular queue`，它是一个环形的队列。
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMzQ2LzM0Nl9jaXJjdWxhcl9xdWV1ZS5wbmc?x-oss-process=image/format,png)

循环队列的主要优点是，通过向循环队列中添加新元素，它会自动丢弃最旧的元素。与 `deque` 不同，我们不需要显式地删除最旧的元素。

循环队列的另一个优点是，一个指针就足以跟踪队列的两端，不像 `deque` 那样，我们必须为每一端保留一个指针。

**算法：**

无需使用任何库，可以轻松实现具有固定大小数组的循环队列。关键是 `head` 和 `tail` 元素的关系，我们可以用以下公式：
$$
\text{tail} = (\text{head} + 1) \mod \text{size}
$$

换句话说，`tail` 元素就在 `head` 元素的旁边。一旦我们向前移动 `head`，我们将覆盖前面的 `tail` 元素。
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMzQ2LzM0Nl9zbmFrZS5wbmc?x-oss-process=image/format,png)

```python [solution3-Python]
class MovingAverage:
    def __init__(self, size: int):
        self.size = size
        self.queue = [0] * self.size
        self.head = self.window_sum = 0
        # number of elements seen so far
        self.count = 0
    
    def next(self, val: int) -> float:
        self.count += 1
        # calculate the new sum by shifting the window
        tail = (self.head + 1) % self.size
        self.window_sum = self.window_sum - self.queue[tail] + val
        # move on to the next head
        self.head = (self.head + 1) % self.size
        self.queue[self.head] = val
        return self.window_sum / min(self.size, self.count)
```

```java [solution3-Java]
class MovingAverage {
  int size, head = 0, windowSum = 0, count = 0;
  int[] queue;
  public MovingAverage(int size) {
    this.size = size;
    queue = new int[size];
  }

  public double next(int val) {
    ++count;
    // calculate the new sum by shifting the window
    int tail = (head + 1) % size;
    windowSum = windowSum - queue[tail] + val;
    // move on to the next head
    head = (head + 1) % size;
    queue[head] = val;
    return windowSum * 1.0 / Math.min(size, count);
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(1)$。我们可以看到在 `next(val)` 函数中没有循环。
* 空间复杂度：$\mathcal{O}(N)$，循环队列使用的大小。