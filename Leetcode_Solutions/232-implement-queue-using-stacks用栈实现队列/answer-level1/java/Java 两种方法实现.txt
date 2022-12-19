//法一 入队要用到栈一s1，s2； 出队只需用到栈一s1。
//该方法主要处理的是入栈操作。入队前，将s2作为中间容器，将s1的数据全部倒入s2，在将元素入队，最后将元素倒回s1
//因为此时s1保持了先进先出的特性，所以出队是直接从s1的栈顶出栈
     
import java.util.Stack;
class MyQueue {
    private Stack<Integer> s1;
    private Stack<Integer> s2;
    /** Initialize your data structure here. */
    public MyQueue() {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        if(s1.isEmpty())
            s1.push(x);
        else{
            while(!s1.isEmpty())
                s2.push(s1.pop());
            s2.push(x);
            while(!s2.isEmpty())
                s1.push(s2.pop());
        }

    }
/** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return s1.pop();
    }

    /** Get the front element. */
    public int peek() {
        return s1.peek();
    }

    //只需要判断s1是否为空，s2仅仅是入队时的一个中间容器
    public boolean empty() {
        return s1.isEmpty();
    }

   
    
}

//法二 入队只需直接s1.push(x)；出队需要用到s1 s2
//出队时，如果s2为空，则将s1的数据全部倒入s2，注意，是全部倒入。倒入之后将栈顶出栈。
//当s2不为空时，则直接s2.pop()

import java.util.Stack;

class MyQueue {

    private Stack<Integer> s1;//输入栈
    private Stack<Integer> s2;//输出栈
    /** Initialize your data structure here. */
    public MyQueue() {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        //只有当输出栈为空时才能向输出栈倒入数据
        if(s2.isEmpty())
            while(!s1.isEmpty())
                s2.push(s1.pop());
        return s2.pop();

    }

    /** Get the front element. */
    public int peek() {
        if(s2.isEmpty())
            while(!s1.isEmpty())
                s2.push(s1.pop());
        return s2.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        // 当输入栈和输出栈同时为空时才能判断为空
        return s1.isEmpty() && s2.isEmpty();
    }
}
