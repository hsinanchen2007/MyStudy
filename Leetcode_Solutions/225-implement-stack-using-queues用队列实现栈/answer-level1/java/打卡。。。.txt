### 解题思路
    设置两个队列 queue1 、  queue2
    始终保持一个队列为空
    1.添加元素：一直向非空队列中添加元素
    2.取出元素：将非空队列中的size-1个元素放入空队列，最后将第size个元素取出并返回
    3.查看队首元素：进行2.中操作取出元素并保存返回，再进行1.中操作将取出元素放入
    4.判断是否为空：判断两个队列是否同时为空

### 代码

```java
class MyStack {

    private Queue<Integer> queue1;
    private Queue<Integer> queue2;

    /** Initialize your data structure here. */
    public MyStack() {
        queue1 = new PriorityQueue<Integer>();
        queue2 = new PriorityQueue<Integer>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        if (queue1.isEmpty()){
            queue2.add(x);
        }else {
            queue1.add(x);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if (queue1.isEmpty()&&!queue2.isEmpty()){
            int size = queue2.size();
            for (int i=0;i<size-1;i++){
                queue1.add(queue2.remove());
            }
            return queue2.remove();
        }else if (!queue1.isEmpty()&&queue2.isEmpty()){
            int size = queue1.size();
            for (int i=0;i<size-1;i++){
                queue2.add(queue1.remove());
            }
            return queue1.remove();
        }else {
            throw new IllegalArgumentException("stack is empty");
        }
    }

    /** Get the top element. */
    public int top() {
        int top = pop();
        push(top);
        return top;
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        if (queue1.isEmpty()&&queue2.isEmpty())
            return true;
        else 
            return false;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
```