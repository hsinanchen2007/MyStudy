题意：使用Stacks来模拟队列的各种方法，如push、pop(这里返回队首值)、peek(得到队首值)、empty等方法。而且最好只使用Stack的标准操作。

思路：使用Stacks，这里的栈是复数！

---
### 解决方法一
pop和peek两个方法中，都使用临时栈。**如果要得到队首值，就将原来的栈中的值全部弹出并依次push进临时栈中，这样临时栈的栈顶就是队列的队头元素**。 
- 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :9.6 MB, 在所有 C++ 提交中击败了5.71%的用户
```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st;
    MyQueue() { }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() { //使用临时栈
        stack<int> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        int data = temp.top(); //得到队列的第一个元素
        temp.pop();
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        return data;
    }
    
    /** Get the front element. */
    int peek() { //使用临时栈
        stack<int> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        int data = temp.top(); //得到队列的第一个元素 
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        return data;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 ```
### 解决方法二
**仅仅**在push方法中使用临时栈，**每次要push一个元素时，就将先前的元素全部弹出放到临时栈中，然后将新的元素放到栈底**，这样就可以用原来的栈实现先进先出了。从这里可以看出，**我们总得在一方面下功夫，要么是输入要么是输出**。
- 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :9.5 MB, 在所有 C++ 提交中击败了5.71%的用户
```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st;
    MyQueue() { }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {  
        int data = st.top(); 
        st.pop();
        return data;
    }
    
    /** Get the front element. */
    int peek() {  
        return st.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
}; 
 ```
### 解决方法三
自带一个输入栈，一个输出栈。如果要输出peek的话，就将全部的input元素全部弹出放到output中，然后返回output的栈顶值。**pop调用peek**，从output的顶部弹出元素，然后才返回记录下的原output栈顶值。不过这里的**判空，需要两个栈都为空**。
- 执行用时 :4 ms, 在所有 C++ 提交中击败了67.51% 的用户
内存消耗 :9.5 MB, 在所有 C++ 提交中击败了5.71%的用户
```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> input, output; //输入输出栈
    MyQueue() { }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {  
        int data = peek();
        output.pop();
        return data;
    }
    
    /** Get the front element. */
    int peek() {  
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        } 
        return output.top();  
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
};
```
