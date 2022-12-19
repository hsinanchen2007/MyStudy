### 解题思路
主要运用2组队列，保证后加进来的数据是在队列的头部，从而实现栈功能的模拟。

### 代码

```java
import java.util.LinkedList;
import java.util.Queue;

public class MyStack {

    Queue<Integer> que1;
    Queue<Integer> que2;
    public MyStack() {
        que1 = new LinkedList<>();
        que2 = new LinkedList<>();
    }
    public void push(int x) {
        que2=que1;
        que1=new LinkedList<>();
        que1.offer(x);
        while(!que2.isEmpty()){
            que1.offer(que2.poll());
        }
    }
    public int pop() {
        return que1.poll();
    }
    public int top() {
        return que1.peek();
    }
    public boolean empty() {
        return que1.isEmpty();
    }

    public static void main(String[] args){
        MyStack test = new MyStack();
        test.push(1);
        test.push(2);
        test.push(3);
        //System.out.print(test);
        System.out.println(test.pop());


    }

}
```