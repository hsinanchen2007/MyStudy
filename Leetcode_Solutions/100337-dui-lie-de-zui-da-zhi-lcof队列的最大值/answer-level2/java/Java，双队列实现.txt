### **思路：**

此题的关键在于 `max_value` 如何实现，`push_back` 和 `pop_front` 都是队列现成的操作。之前做过栈类似的题目：[155. 最小栈](https://leetcode-cn.com/problems/min-stack/)，[面试题30. 包含min函数的栈](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)。在这里可以运用类似的思想，用两个队列实现题目要求。

题目要求找出队列中的最大值，注意到：**当一个元素进入队列的时候，它前面所有比它小的元素就不会再对答案产生影响**。

按照这个思路，可以在元素入队时进行如下的操作：从队列尾部入队元素`value`时，提前取出队列中所有比`value`小的元素，使得队列中只保留对结果有影响的数字。这样等价于要求维持队列单调递减，即要保证每个元素的前面都没有比它小的元素。

**具体实现：** 在入队元素`value`时，先从队列尾部依次取出比`value`小的元素，直到遇到比`value`大的元素为止，这就保证了这个队列是单调递减的。因此设立一个双端队列`deque`来存储这个递减队列，另设一个普通队列`queue`存储所有元素。

+ `push_back`：`queue`入队；对`deque`进行上述检查后决定是否入队。
+ `pop_front`：`queue`出队；若出队元素与`deque`队首元素相等，`deque`出队。
+ `max_value`：`deque`队首元素。

``` Java
class MaxQueue {
    // 辅助队列
    private Queue<Integer> queue;
    // 双端队列
    private Deque<Integer> deque;

    public MaxQueue() {
        queue = new LinkedList<>();
        deque = new ArrayDeque<>();
    }
    
    public int max_value() {
        if (deque.isEmpty()) {
            return -1;
        }
        return deque.peekFirst();
    }
    
    public void push_back(int value) {
        while (!deque.isEmpty() && deque.peekLast() < value) {
            deque.removeLast();
        }
        deque.addLast(value);
        queue.add(value);
    }
    
    public int pop_front() {
        if (queue.isEmpty()) {
            return -1;
        }
        int result = queue.peek();
        if (result == deque.peek()) {
            deque.remove();
        }
        queue.remove();
        return result;
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */
```