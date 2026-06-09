### 解题思路
【利用2个栈来实现队列的功能】先定义2个栈first和second, 向队列中添加元素时就把元素放入first栈中（有一个前提条件：需要先判断second栈是否为空，若不为空，就需要把second栈中元素全部依次弹出入栈到first栈中），
从队列中取元素时就从second栈顶取（有一个前提条件：需要先判断first栈中的元素是否为空，若不为空，就需要把first栈中的元素全部依次弹出然后入栈到second中）。

### 代码

```java
class MyQueue {

    /**
     * 初始化队列
     */
    public MyQueue() {
        //利用2个栈实现一个队列
        first = new Stack();
        second = new Stack();
    }

    /**
     * 将一个元素放入队列的尾部
     *
     * @param x
     */
    public void push(int x) {
        // 向第一个栈中添加元素时，需要先判断第二栈中的元素是否为空，
        // 如果第二个栈中的元素不为空，就需要把第二个栈中的元素全部出栈后入栈到第一个栈中
        if (!second.empty()) {
            int p = second.pop();
            first.push(p);
        }
        first.push(x);
    }

    /**
     *  从队列首部移除元素
     */
    public int pop() {
        while(!first.empty()) {
            int x = first.pop();
            second.push(x);
        }
        return second.pop();
    }

    /**
     * 返回队列首部的元素
     * @return
     */
    public int peek() {
        while(!first.empty()) {
            int x = first.pop();
            second.push(x);
        }
        int result = second.peek();
        return result;
    }

    /**
     * 返回队列是否为空
     * @return
     */
    public boolean empty() {
        return first.empty() && second.empty();
    }

    private Stack<Integer> first = null;
    private Stack<Integer> second = null;
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