![微信图片_20190801155927.jpg](https://pic.leetcode-cn.com/4aa08a4e1b0b506b32bc68e5c61e70faae84e10424e8a83b931a0adb90983ef6-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190801155927.jpg)

代码如下:
```
class MyQueue {
    Stack<Integer> stackPush;
    Stack<Integer> stackPop;
    /** Initialize your data structure here. */
    public MyQueue() {
        stackPush = new Stack<Integer>();
        stackPop = new Stack<Integer>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        stackPush.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(stackPush.empty() && stackPop.empty()){
            throw new RuntimeException("queue is empty");
        }else if(stackPop.empty()){
            //把第一个栈中的数据转到第二个栈中;
            while(!stackPush.empty()){
                stackPop.push(stackPush.pop());
            }
        }
        
        return stackPop.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        if(stackPop.empty() && stackPush.empty()){
            throw new RuntimeException("queue is empty");
        }else if(stackPop.empty()){//stackPop 必须为空才可以;
            while(!stackPush.empty()){
                stackPop.push(stackPush.pop());
            }
            
        }
        return stackPop.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        if(stackPop.empty() && stackPush.empty()){
            return true;
        }
        return false;
    }
    
     public static void main(String[] args){
      MyQueue obj = new MyQueue();
      obj.push(1);
      int param_3 = obj.peek();
      int param_2 = obj.pop();
      
      boolean param_4 = obj.empty();
      System.out.println(param_3);
    }
}





```

