解题：
1 栈和队列不同的地方在于，栈是先进后出，队列是先进先出，解决问题的根源再次，如果使用栈能做到先进先出
2 一个栈的结构是固定的，这时候就可以使用两个栈，在java中栈是继承了Vector这个类，有兴趣可以了解一下
3 两个栈，一个栈存储的是正常栈顺序的数据，另一个栈存储的是和第一个栈相反顺序的数据
4 考虑到用相反数据的栈会比较多一些，pop、peek、empty，所以耗时的算法可以写在push里，其他直接取都是O(1)
5 实现思路可以看代码，比较直观，三步操作



```java
package com.aizain.jhome.computer.data.queue;

import java.util.Stack;

/**
 * QueueByStack
 * 用栈实现队列
 *
 * 使用栈实现队列的下列操作：
 *
 * push(x) -- 将一个元素放入队列的尾部。
 * pop() -- 从队列首部移除元素。
 * peek() -- 返回队列首部的元素。
 * empty() -- 返回队列是否为空。
 * 示例:
 *
 * MyQueue queue = new MyQueue();
 *
 * queue.push(1);
 * queue.push(2);
 * queue.peek();  // 返回 1
 * queue.pop();   // 返回 1
 * queue.empty(); // 返回 false
 * 说明:
 *
 * 你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
 * 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 * 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/implement-queue-using-stacks
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author Zain
 * @date 2019/11/2
 */
public class QueueByStack {

    private Stack<Integer> inStack;
    private Stack<Integer> outStack;

    /** Initialize your data structure here. */
    public QueueByStack() {
        inStack = new Stack<>();
        outStack = new Stack<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        while (!outStack.empty()) {
            inStack.push(outStack.pop());
        }

        inStack.push(x);

        while (!inStack.empty()) {
            outStack.push(inStack.pop());
        }

    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return outStack.pop();
    }

    /** Get the front element. */
    public int peek() {
        return outStack.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return outStack.empty();
    }

}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */

```

**附上单元测试**

```java
package com.aizain.jhome.computer.data.queue;

import lombok.extern.slf4j.Slf4j;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

@Slf4j
class QueueByStackTest {

    private QueueByStack queueByStack = new QueueByStack();

    @BeforeEach
    void setUp() {
        queueByStack = new QueueByStack();
    }

    @Test
    void push() {
        queueByStack.push(1);
        queueByStack.push(2);
    }

    @Test
    void pop() {
        queueByStack.push(1);
        queueByStack.push(2);
        assertEquals(1, queueByStack.pop());
        assertEquals(2, queueByStack.pop());
    }

    @Test
    void peek() {
        queueByStack.push(1);
        queueByStack.push(2);
        assertEquals(1, queueByStack.peek());
        assertEquals(1, queueByStack.peek());
        assertEquals(1, queueByStack.pop());
        assertEquals(2, queueByStack.peek());
    }

    @Test
    void empty() {
        assertTrue(queueByStack.empty());
        queueByStack.push(1);
        assertFalse(queueByStack.empty());
    }
}
```