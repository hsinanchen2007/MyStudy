### 解题思路
思路很讲单，用两个队列模拟一个栈，始终保持一个队列为空，另一个队列存放元素，如果要出栈或者取栈顶元素（两个方法原理相同），直接将有元素的队列的除最后一个元素外的所有元素移到另一个队列，然后再返回前者的元素即可，根据具体是pop还是top来选择是直接删除并返回，还是先存下来移到另一个队列再返回。
### 代码

```java
class MyStack {
    Queue<Integer> queue1;
    Queue<Integer> queue2;
    /** Initialize your data structure here. */
    public MyStack() {
        queue1 = new ArrayDeque<>();
        queue2 = new ArrayDeque<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        if(queue2.size() == 0) queue1.add(x);
        else queue2.add(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(queue1.size() > 0){
            while(queue1.size() > 1){
                queue2.add(queue1.remove());
            }
            return queue1.remove();
        }else{
            while(queue2.size() > 1){
                queue1.add(queue2.remove());
            }
            return queue2.remove();
        }
    }
    
    /** Get the top element. */
    public int top() {
        if(queue1.size() > 0){
            while(queue1.size() > 1){
                queue2.add(queue1.remove());
            }
            int res = queue1.remove();
            queue2.add(res);
            return res;
        }else{
            while(queue2.size() > 1){
                queue1.add(queue2.remove());
            }
            int res = queue2.remove();
            queue1.add(res);
            return res;
        }
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        if(queue1.size() > 0 || queue2.size() > 0) return false;
        else return true;
    }
}


```