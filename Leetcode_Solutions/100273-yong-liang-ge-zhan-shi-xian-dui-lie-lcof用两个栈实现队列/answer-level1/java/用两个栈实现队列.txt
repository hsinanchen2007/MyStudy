使用两个栈`stack1`和`stack2`，其中`stack1`用于存储元素，`stack2`作为添加元素时的辅助栈。另外使用变量`size`存储队列中的元素个数。
构造方法：初始化`stack1`和`stack2`为空栈，`size`为0。
方法`appendTail`：添加元素，首先将`stack1`的所有元素依次弹出并压入`stack2`，然后将新元素压入`stack1`，最后将`stack2`的所有元素依次弹出并压入`stack1`。添加元素后将`size`加1。这样操作可保证最新添加的元素在`stack1`的底部，将被最后弹出，而最早添加的元素会最先弹出。
方法`deleteHead`：首先判断`size`是否为0，若为0则队列为空，返回-1，若不为0，则将`size`减1，弹出`stack1`的一个元素并返回该元素。
```
class CQueue {
    Stack<Integer> stack1;
    Stack<Integer> stack2;
    int size;

    public CQueue() {
        stack1 = new Stack<Integer>();
        stack2 = new Stack<Integer>();
        size = 0;
    }
    
    public void appendTail(int value) {
        while (!stack1.isEmpty())
            stack2.push(stack1.pop());
        stack1.push(value);
        while (!stack2.isEmpty())
            stack1.push(stack2.pop());
        size++;
    }
    
    public int deleteHead() {
        if (size == 0)
            return -1;
        size--;
        return stack1.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```
