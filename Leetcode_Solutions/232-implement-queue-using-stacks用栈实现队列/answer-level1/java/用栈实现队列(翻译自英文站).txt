> 原文地址 [implement-queue-using-stacks](https://leetcode.com/problems/implement-queue-using-stacks/solution/)

本文适合初学者。它介绍了以下想法：Queue，Stack。

## 解法

队列是**FIFO**（**先进先出**）数据结构，其中元素从一侧插入 - `rear`并从另一侧移除 - `front`。实现它的最直观的方法是链表，但本文将介绍使用栈的另一种方法。Stack是**LIFO**（后进先出）数据结构，其中元素是从同一端添加和删除的，被称为`top`。为了满足队列的**FIFO**属性，我们需要保留两个栈。它们用于反转元素的到达顺序，其中一个以最终顺序存储队列元素。

## 方法1（两个栈）Push - O(n) per operation, Pop - O(1) per operation.

**算法**

**Push**

队列是FIFO（先进先出），但栈是LIFO（后进先出）。这意味着必须将最新元素推到堆栈的底部。为此，我们首先将所有`s1`元素传输到辅助栈`s2`。然后将新到达的元素推到顶部，`s2`并弹出所有元素并将其推送到`s1`。

![](https://pic.leetcode-cn.com/058b17a952b170db99bf5c07409e3490c39803b30412c045eddcd93d0396acbf-file_1560855897745)

*图1.将元素推入队列中*

**Java的**

```java
 public void push(int x) {
   while (!s1.isEmpty())
     s2.push(s1.pop());
   s2.push(x);
   while (!s2.isEmpty())
     s1.push(s2.pop());
 }
```

**复杂性分析**

- 时间复杂度： O(n)。

除了新到达之外，每个元素都被按下并弹出两次。最后插入的元素被弹出并按下一次。因此，这给了 4 n + 24 *n*+2 运营在哪里ñ*n*是队列大小。在 `push`和`pop`操作有O(1)时间复杂度。

- 空间复杂度： O(n)。我们需要额外的内存来存储队列元素

**Pop**

该算法从堆栈中弹出一个元素`s1`，因为`s1`它总是在其顶部存储队列中的第一个插入元素。队列的前端元素保持为`front`。

![](https://pic.leetcode-cn.com/3c6e703bb1f27b86a155d3d2c9a267992a9ae1ea1acc3144519c0544cdde8a4e-file_1560855898027)

*图2.从队列中弹出一个元素*

**Java**

```java
// Removes the element from the front of queue.
public void pop() {
    return s1.pop();
}
```

**复杂性分析**

- 时间复杂度： O(1)。
- 空间复杂度： O(1)。

**空**

堆栈`s1`包含所有堆栈元素，因此算法会检查`s1`大小以在队列为空时返回。

```java
// Return whether the queue is empty.
public boolean empty() {
    return s1.isEmpty();
}
```

时间复杂度： O(1)。

空间复杂度： O(1)。

**Peek**

的`front`元件被保持在恒定存储器，当我们推或弹出元件被修改。

```java
// Get the front element.
public int peek() {
  	return s1.peek();
}
```

时间复杂度： O（1）。该`front`元素已提前计算，仅在`peek`运行中返回。

空间复杂度： O（1）。

**完整代码**

```java
public class MyQueue {

    private Stack<Integer> s1 = new Stack<>();
    private Stack<Integer> s2 = new Stack<>();


    /** Initialize your data structure here. */
    public MyQueue() {

    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        while (!s1.isEmpty())
            s2.push(s1.pop());
        s2.push(x);
        while (!s2.isEmpty())
            s1.push(s2.pop());
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return s1.pop();
    }

    /** Get the front element. 获取头元素 */
    public int peek() {
        return s1.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return s1.isEmpty();
    }
}
```

------

## 方法2（两个栈）Push - O(1) per operation, Pop - Amortized O(1) per operation.**算法**

**Push**

新到达的元素总是添加到堆栈顶部，`s1`第一个元素保留为`front`队列元素

![](https://pic.leetcode-cn.com/f43500e6954ba8078942d17eceeb0f38684679ea07e6f8d552e337361639f917-file_1560855897697)

*图3.将元素推入队列中*

**Java**

```java
private Stack<Integer> s1 = new Stack<>();
private Stack<Integer> s2 = new Stack<>();

// Push element x to the back of queue.
public void push(int x) {
    if (s1.empty())
        front = x;
    s1.push(x);
}
```

**复杂性分析**

- 时间复杂度： O（1）。

将元素添加到堆栈是O（1）操作。

- 空间复杂度： O（n）。我们需要额外的内存来存储队列元素

**Pop**

我们必须删除队列前面的元素。这是堆栈中第一个插入的元素，`s1`由于堆栈的`LIFO (last in - first out)`策略，它位于堆栈的底部。要删除底部元素 `s1`，我们必须弹出所有元素`s1`并将它们推送到另一个堆栈`s2`，这有助于我们以`s1`相反的顺序存储元素。这样底部元素`s1`将位于顶部，`s2`我们可以简单地从堆栈中弹出它`s2`。一旦`s2`是空的，从算法传输数据`s1`到`s2`一次。

![](https://pic.leetcode-cn.com/d17565e0921bff18c695ff6be29d3a4b078929f8d1243339107e597dd75754dc-file_1560855897762)

*图4.从堆栈中弹出一个元素*

**Java**

```java
// Removes the element from in front of queue.
public void pop() {
    if (s2.isEmpty()) {
        while (!s1.isEmpty())
            s2.push(s1.pop());
    }
    s2.pop();    
}
```

**复杂性分析**

- 时间复杂度：摊销 O（1），最坏情况O（n）。

In the worst case scenario when stack `s2` is empty, the algorithm pops n*n* elements from stack s1 and pushes n*n* elements to `s2`, where n*n* is the queue size. This gives 2n2*n* operations, which is O(n)*O*(*n*). But when stack `s2` is not empty the algorithm has O(1) time complexity. So what does it mean by Amortized O(1)*O*(1)? Please see the next section on Amortized Analysis for more information.

- 空间复杂度： O（1）。

**Amortized Analysis**

Amortized analysis gives the average performance (over time) of each operation in the worst case. The basic idea is that a worst case operation can alter the state in such a way that the worst case cannot occur again for a long time, thus amortizing its cost.

Consider this example where we start with an empty queue with the following sequence of operations applied:

push_1, push_2, \ldots, push_n, pop_1,pop_2 \ldots, pop_n*p**u**s**h*1,*p**u**s**h*2,…,*p**u**s**h**n*,*p**o**p*1,*p**o**p*2…,*p**o**p**n*

The worst case time complexity of a single pop operation is O(n)*O*(*n*). Since we have n*n* pop operations, using the worst-case per operation analysis gives us a total of O(n^2)*O*(*n*2) time.

However, in a sequence of operations the worst case does not occur often in each operation - some operations may be cheap, some may be expensive. Therefore, a traditional worst-case per operation analysis can give overly pessimistic bound. For example, in a dynamic array only some inserts take a linear time, though others - a constant time.

In the example above, the number of times pop operation can be called is limited by the number of push operations before it. Although a single pop operation could be expensive, it is expensive only once per `n` times (queue size), when `s2` is empty and there is a need for data transfer between `s1` and `s2`. Hence the total time complexity of the sequence is : `n` (for push operations) + `2*n` (for first pop operation) + `n - 1` ( for pop operations) which is O(2*n)*O*(2∗*n*).This gives O(2n/2n)*O*(2*n*/2*n*) = O(1)*O*(1) average time per operation.

**Empty**

堆栈`s1`并`s2`包含所有堆栈元素，因此算法检查`s1`并`s2`在队列为空时返回大小。

```java
// Return whether the queue is empty.
public boolean empty() {
    return s1.isEmpty() && s2.isEmpty();
}
```

时间复杂度： O（1）。

空间复杂度： O（1）。

**Peek**

的`front`元件被保持在恒定存储器和当我们推元件被修改。当`s2`不为空时，前部元素位于顶部`s2`

```java
// Get the front element.
public int peek() {
    if (!s2.isEmpty()) {
        return s2.peek();
    }
    return front;
}
```

时间复杂度： O（1）

该`front`元素先前已计算或作为堆栈的顶部元素返回`s2`。因此复杂性是O（1）

空间复杂度： O（1）

**完整代码**

```java
public class MyQueue {

    private Stack<Integer> s1 = new Stack<>();
    private Stack<Integer> s2 = new Stack<>();

    private int front;

    /** Initialize your data structure here. */
    public MyQueue() {

    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        if (s1.empty())
            front = x;
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty())
                s2.push(s1.pop());
        }
        return s2.pop();
    }

    /** Get the front element. */
    public int peek() {
        if (!s2.isEmpty()) {
            return s2.peek();
        }
        return front;
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return s1.isEmpty() && s2.isEmpty();
    }
}
```

Analysis written by: @elmirap.

## 注意事项

翻译自英文站，翻译不准确，详情查看英文站题解


