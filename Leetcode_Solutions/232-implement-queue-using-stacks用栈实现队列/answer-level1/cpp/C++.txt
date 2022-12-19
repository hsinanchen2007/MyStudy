### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyQueue {
    private:stack<int> s1;
    private:stack<int> s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
       
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x=s2.top();
        s2.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
       if(s2.empty())
       {
            while(s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
       }
       return  s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
       if(s1.empty()&&s2.empty())return true;
       else  return false;
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




//  void push(int x) {
//         a.push(x);
//     }
    
//     /** Removes the element from in front of queue and returns that element. */
//     int pop() {
//         /*
//         if(b.empty()){
//             b.push(a.peek());
//         }
//        return b.top;*/

//        if(b.empty()){
//             while(a.size()) {
//                 b.push(a.top());
//                 a.pop();
//             }
//         }
//         int x=b.top();
//         b.pop();
//         return x;


//     }
    
//     /** Get the front element. */
//     int peek() {
//       /* if(b.empty())
//        {
//             b.push(a.top());
//        }
//        return b.top;
//        */
//        if(b.empty()){
//             while(a.size()) {
//                 b.push(a.top());
//                 a.pop();
//             }
//         }
//         return b.top();
//     }
    
//     /** Returns whether the queue is empty. */
//     bool empty() {
//         if(a.empty()&&b.empty())
//             return true;
//         else
//             return false;
//     }
```