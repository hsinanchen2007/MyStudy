### 解题思路
其他方法不变，出栈就是出队，栈顶就是队头，判断栈空就是判断队列空。
入栈稍作改动，如果队列为空则直接入队就行。
如果队列里有东西我们需要把他排到队列后面

### 代码

```java
import java.util.LinkedList;
import java.util.Queue;

public class MyStack {

    /** Initialize your data structure here. */
    public MyStack() {

    }
    Queue<Integer> queue = new LinkedList<Integer>();
    /** Push element x onto stack. */
    public void push(int x) {
        if (queue.size()==0){
            queue.add(x);
        }else{
            int size=queue.size();
            queue.add(x);
            for (int i = 0; i <size ; i++) {
                queue.add(queue.poll());
            }
            /*int[] a=new int[size];
            for (int i = 0; i <size ; i++) {
                a[i]=queue.poll();
            }
            queue.add(x);
            for (int i = 0; i <a.length ; i++) {
                queue.add(a[i]);
            }*/

        }

    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return queue.poll();
    }

    /** Get the top element. */
    public int top() {
        return queue.peek();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        if (queue.size()==0)return true;
        return false;
    }

    public static void main(String[] args) {
        MyStack stack=new MyStack();
        stack.push(5);
        System.out.println("是否为空："+stack.empty()+" 栈顶为："+stack.top()+" 弹出一个："+stack.pop());
        stack.push(4);
        stack.push(3);

        stack.push(2);
        System.out.println("是否为空："+stack.empty()+" 栈顶为："+stack.top()+" 弹出一个："+stack.pop());
        System.out.println("是否为空："+stack.empty()+" 栈顶为："+stack.top()+" 弹出一个："+stack.pop());
        System.out.println("是否为空："+stack.empty()+" 栈顶为："+stack.top()+" 弹出一个："+stack.pop());
        stack.push(1);
//        System.out.println("是否为空："+stack.empty()+" 栈顶为："+stack.top()+" 弹出一个："+stack.pop()+" 栈顶为："+stack.top());
//        System.out.println("是否为空："+stack.empty()+" 栈顶为："+stack.top()+" 弹出一个："+stack.pop()+" 栈顶为："+stack.top());
//        System.out.println("是否为空："+stack.empty()+" 栈顶为："+stack.top()+" 弹出一个："+stack.pop()+" 栈顶为："+stack.top());
//        System.out.println("是否为空："+stack.empty()+" 栈顶为："+stack.top()+" 弹出一个："+stack.pop()+" 栈顶为："+stack.top());
//        System.out.println("是否为空："+stack.empty()+" 栈顶为："+stack.top()+" 弹出一个："+stack.pop()+" 栈顶为："+stack.top());
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