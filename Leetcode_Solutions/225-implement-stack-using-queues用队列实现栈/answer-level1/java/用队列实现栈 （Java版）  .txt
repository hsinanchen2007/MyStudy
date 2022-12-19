### 解题思路
创建两个队列a、b来实现栈的功能。（在没有任何元素进队时，队列b始终保持队首为栈顶部，队尾为栈底的顺序）
进栈操作：先将待入栈元素x push（）到队列a中，然后将队列b中的元素全部push（）到队列a中，这样队列a中的元素就保持队首为栈顶部，队尾为栈底的顺序，最后将队列a、b交换使得队列b始终保持队首为栈顶部，队尾为栈底的顺序。。
出栈操作：由于队列b保持队首为栈顶部，队尾为栈底的顺序，则直接从队列b中取出队首元素

### 代码

```java
import java.util.LinkedList;
import java.util.Queue;

class MyStack {
	
    private Queue<Integer> a;//输入队列
    private Queue<Integer> b;//输出队列
	
    /** Initialize your data structure here. */
    public MyStack() {
    	a = new LinkedList<>();
        b = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
    	a.offer(x);
        // 将b队列中元素全部转给a队列
        while(!b.isEmpty())
            a.offer(b.poll());
        // 交换a和b,使得a队列没有在push()的时候始终为空队列
        Queue temp = a;
        a = b;
        b = temp;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
    	return b.poll();
    }
    
    /** Get the top element. */
    public int top() {
    	 return b.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
    	 return b.isEmpty();
    }
}
```