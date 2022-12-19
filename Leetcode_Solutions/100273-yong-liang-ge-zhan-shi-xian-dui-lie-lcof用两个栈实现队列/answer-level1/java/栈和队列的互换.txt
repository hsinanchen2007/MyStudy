### 解题思路
用两个栈构建队列，设两个栈分别为A，B。
A负责添加，B负责删除，
首先在A中添加，要删除时先将A中所有元素移至B，从栈顶删除即可。
删除时先检查，当B为空时，说明要移动A里的元素了。

### 代码

```java
class CQueue {
    LinkedList<Integer> stackA, stackB;
    public CQueue() {
        stackA = new LinkedList<Integer>();
        stackB = new LinkedList<Integer>();
    }
    public void appendTail(int value) {
        stackA.push(value);
    }
    public int deleteHead() {
        if(!stackB.isEmpty()) return stackB.pop();
        if(stackA.isEmpty()) return -1;
        while(!stackA.isEmpty()){
            stackB.push(stackA.pop());
        }
        return stackB.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```
### 队列构建栈

队列只能先进先出，要删除末尾，A中添加元素，
要删除时先将末尾之前的元素移至B，删除A中元素，A为空，
需要，转换A,B。

### 代码

```java
class Stack {
    LinkedList<Integer> queueA, queueB;
    public Stack() {
        queueA = new LinkedList<Integer>();
        queueB = new LinkedList<Integer>();
    }
    public void push(int value) {
        queueA.offer(value);
    }
    public int pop() {
        if(queueA.size() == 0) return -1;
        while(queueA.size() > 1){
            queueB.offer(queueA.poll());
        }
        LinkedList<> temp = queueA;
        queueA = queueB;
        queueB = temp;
        return queueB.poll();
    }
}

```