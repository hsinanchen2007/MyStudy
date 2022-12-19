### 解题思路
唯一值得讲解的就是出栈的操作了，使用两个队列A，B，出栈时。将A中除最后一个外的所有元素remove并添加到队列B中，然后remove并返回A中的最后一个元素，再将B中的全部元素remove并添加到A中，size--；所有的操作就完成了

### 代码

```java
class MyStack {
    
    ArrayList<Integer> queueA;
    ArrayList<Integer> queueB;
    
    int size;
    /** Initialize your data structure here. */
    public MyStack() {
        this.queueA = new ArrayList<>();
        this.queueB = new ArrayList<>();
        this.size = 0;
    }

    /** Push element x onto stack. */
    public void push(int x) {
        queueA.add(x);
        size++;
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        while(queueA.size() != 1) {
            queueB.add(queueA.remove(0));
        }
        int ret = queueA.remove(0);
        
        while(queueB.size() != 0) {
            queueA.add(queueB.remove(0));
        }
        size--;
        return ret;
    }

    /** Get the top element. */
    public int top() {
        return queueA.get(queueA.size() - 1);
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return size == 0;
    }
}
```