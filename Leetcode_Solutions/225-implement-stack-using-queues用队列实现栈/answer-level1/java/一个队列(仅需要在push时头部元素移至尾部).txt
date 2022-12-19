### 窃以为打卡活动只会让想找题解的人找不到满意的解法(当然我自己的解法不见得好)

仅push()需要额外处理，将新插入的尾部元素移至头部即可一劳永逸(先退出的是头部元素)
1.用一个for loop将头部的元素全部移出poll()
2.退出的头部元素add()进入尾部

### java代码

```java
class MyStack {

    Queue<Integer> queue;
    public MyStack() {
        queue=new LinkedList<Integer>();
    }
    
    
    public void push(int x) {
        //队列的插入是放在尾部,而先退出队列的是头部，需要在add()之后将尾部元素调至头部
        queue.add(x);
        int len=queue.size();
        while(len>1){
            int head=queue.poll();//队列头部的元素,退出队列
            queue.add(head);//将原先头部的元素add()进入尾部
            len--;
        }
    }
    
    
    public int pop() {
        return queue.poll();
    }
    
    
    public int top() {
        return queue.peek();
    }
    
    
    public boolean empty() {
        return queue.size()==0?true:false;
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