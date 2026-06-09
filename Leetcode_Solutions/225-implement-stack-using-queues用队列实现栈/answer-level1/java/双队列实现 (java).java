### 解题思路
- 一个队列保持为空，另一个不为空
- push()就往不空的队列里push
- pop()就将不空队列的所有元素(除最后一个)移到空队列里，最后一个弹出返回即可
- top()就将不空队列的所有元素(除最后一个)移到空队列里，**最后一个用临时变量保存，保存后再弹出移到原来的空队列里。**
- empty()返回两个队列是否都为空
### 代码

```java
class MyStack {

    LinkedList<Integer> list1 = new LinkedList<>();
    LinkedList<Integer> list2 = new LinkedList<>();

    /** Initialize your data structure here. */
    public MyStack() {

    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        if(!list1.isEmpty()){
            list1.offer(x);
        }else{
            list2.offer(x);
        }
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(!list1.isEmpty() && list2.isEmpty()){
            while(list1.size() > 1){
                int tmp = list1.poll();
                list2.offer(tmp);
            }
            return list1.poll();
        }else{
            while(list2.size() > 1){
                int tmp = list2.poll();
                list1.offer(tmp);
            }
            return list2.poll();
        }
        
    }
    
    /** Get the top element. */
    public int top() {
        int top = 0;
        if(!list1.isEmpty() && list2.isEmpty()){
            while(list1.size() > 1){
                int tmp = list1.poll();
                list2.offer(tmp);
            }

            top =  list1.peek();
            list2.offer(list1.poll());
        }else{
            while(list2.size() > 1){
                int tmp = list2.poll();
                list1.offer(tmp);
            }
            top =  list2.peek();
            list1.offer(list2.poll());
        }
        return top;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return list1.isEmpty() && list2.isEmpty();
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