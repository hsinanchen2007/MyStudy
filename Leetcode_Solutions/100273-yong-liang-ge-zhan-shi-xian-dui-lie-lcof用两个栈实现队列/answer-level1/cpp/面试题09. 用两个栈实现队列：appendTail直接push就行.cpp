### 解题思路
此处撰写解题思路

### 代码

```cpp
class CQueue {
public:
    CQueue() {

    }
    void appendTail(int value)
    {
        // 不用管两个栈的内容，直接push
        helper_stack.push(value);
    }
    int deleteHead()
    {
        // 如果第一个栈为空，那么就看那个接受队尾的栈，如果非空，则全部转到队头的栈中，如果为空，即两个栈都为空，返回-1. 注意不应用&&判断队头栈和队尾栈时候同时为空，因为当其中一个非空，你无法判断哪个非空。
        if(data_stack.empty())
        {
            if(helper_stack.empty())
                return -1;
            while(!helper_stack.empty())
            {
                data_stack.push(helper_stack.top());
                helper_stack.pop();
            }
        }
        // 如果第一个栈不为空，即队头栈不为空，出队直接队头栈弹出就行。
        int res = data_stack.top();
        data_stack.pop();
        return res;
        // 切记：pop和top要在对的栈使用，别记混了。
    }
private:
    stack<int> data_stack;  // 队头栈
    stack<int> helper_stack;// 队尾栈
};


    // void appendTail(int value) {
    //     while(!data_stack.empty()){
    //         m_stack.push(data_stack.top());
    //         data_stack.pop();
    //     }
    //     m_stack.push(value);
    //     while(!m_stack.empty()){
    //         data_stack.push(m_stack.top());
    //         m_stack.pop();
    //     }
    // }
    
    // int deleteHead() {
    //     if(data_stack.empty()) return -1;
        
    //     int x = data_stack.top();
    //     data_stack.pop();
    //     return x;
    // }


//     CQueue() {
//         // size = 0;
//     }
    
//     void appendTail(int value) {
//         if(data_stack.empty())
//         {
//             data_stack.push(value);
//            // ++size;
//         }
//         else
//         {
//              while(!data_stack.empty())
//             {
//                 helper_stack.push(data_stack.top());
//                 data_stack.pop();
//             }
//             data_stack.push(value);
//               // ++size;
//             while(!helper_stack.empty())
//             {
//                 data_stack.push(helper_stack.top());
//                 helper_stack.pop();
//             }
//         }
       
            

//     }
    
//     int deleteHead() {
//         // int res;
//         // if(!helper_stack.empty())
//         // {
//         //     res = helper_stack.top();
//         //     helper_stack.pop();
//         //     return res;
            
//         // }
//         // while(!data_stack.empty())
//         // {
//         //     res = data_stack.top();
//         //     helper_stack.push(res);
//         //     data_stack.pop();
//         // }
//         if(data_stack.empty())
//             return -1;
//         int res = data_stack.top();
//         data_stack.pop();
//        // size--;
//         return res;
//     }
// private:
//     stack<int> data_stack;
//     stack<int> helper_stack;
//    // int size;
// };

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```