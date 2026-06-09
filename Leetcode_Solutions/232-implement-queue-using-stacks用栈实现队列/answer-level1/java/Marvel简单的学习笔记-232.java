## 两种解法

### 解法一：压入O(n)弹出O(1)
使用双栈，其中一个为辅助栈。
压入新元素前，将stack已有的元素逐一压入aux，然后新元素压入stack，再把aux所有元素逐一压回到stack。此后stack中元素的存储情况与队列相同。
由于栈后进先出的特性，将一个栈的元素逐一压入另一个栈时，元素的在栈中的排布会发生颠倒，因此可以上述操作可以实现队列。

代码：
```java
class MyQueue {
    private Stack<Integer> stack;
    private Stack<Integer> aux;

    /** 
     * 初始化
     */
    public MyQueue() {
        stack = new Stack<Integer>();
        aux = new Stack<Integer>();
    }
    
    /** 
     * 入列
     */
    public void push(int x) {
        while(!stack.isEmpty())
            aux.push(stack.pop());
        stack.push(x);
        while(!aux.isEmpty())
            stack.push(aux.pop());
    }
    
    /** 
     * 出列
     */
    public int pop() {
        return stack.pop();
    }
    
    /** 
     * 队首元素
     */
    public int peek() {
        return stack.peek();
    }
    
    /** 
     * 是否为空
     */
    public boolean empty() {
        return stack.isEmpty();
    }
}
```

### 解法二：压入O(1)弹出O(1)
或许有人会问，能不能只用一个栈实现队列，就像用队列实现栈时也可以只依赖一个队列。
答案是不行。之所以可以只依赖一个队列实现栈，是因为队列其实可以在两个地方操作：offer()放到队尾，poll()从队首取出。而栈无论是push()还是pop()都只能在栈顶一个地方操作，因此需要借助双栈。

解法一中的压入复杂度为O(n)，可以继续改进：
在第一次出列操作前，不管多少元素入列，都直接压入栈stack1。
当需要出列时，我们想要的是此时栈底的元素，显然O(1)复杂度是不可能取出栈底元素的。那为什么还说弹出O(1)呢？这个疑问等会再解答。
既然O(1)取不出栈底元素，我们就老老实实用O(n)将stack1所有元素逐一弹出放到stack2，这样元素在栈中的排布会颠倒，此时stack2的栈顶元素就是我们需要弹出的stack1的栈底元素。
如果之后仍然是弹出操作，则继续在stack2执行O(1)的弹出即可。
如果需要压入，则还是压到stack1中，弹出则在stack2中，直至stack2为空后，下次弹出还是把stack1中的元素放到stack2。
总之，只要stack2不空则pop()和top()操作都直接在stack2中完成，复杂度都是O(1)；若stack2空，则把stack1中所有元素再逐一压入stack2，则stack1的栈底元素又成为stack2的栈顶元素了。

现在的问题是，为什么上文提到的弹出操作时而是O(n)时而又是O(1)呢？这时因为弹出操作并不总是O(n)，只有当n次压入后，stack2又为空，此时的一次弹出才是O(n)，因为要把stack1中的元素倒腾到stack2中。但此后所有弹出就都可以在stack2中完成了，且复杂度为O(1)。
这样一来，我们说的弹出O(1)其实是均摊后的复杂度。将n个元素从stack1转移到stack2，由于栈后进先出的特性，元素排布发生了颠倒，此后所有弹出都是O(1)，这n次弹出复杂度为O(n)，均摊后平均每次弹出就是O(1)。

代码：
```java
class MyQueue {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public MyQueue() {
        stack1 = new Stack<Integer>();
        stack2 = new Stack<Integer>();
    }
    
    public void push(int x) {
        stack1.push(x);
    }
    
    public int pop() {
        if(stack2.isEmpty())
            while(!stack1.isEmpty())
                stack2.push(stack1.pop());
        return stack2.pop();
    }
    
    public int peek() {
        if(stack2.isEmpty())
            while(!stack1.isEmpty())
                stack2.push(stack1.pop());
        return stack2.peek();
    }
    
    public boolean empty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }
}
```