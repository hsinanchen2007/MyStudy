### 解题思路


一个能用的C++代码，思路前面的大神都已经讲清楚了。主要是C++实现，有些语法和对栈的操作不是很熟练。

### 代码

```cpp
class CQueue {
public:
    stack<int> stackA;
    stack<int> stackB;
    int Bhead=0;//B栈为A栈的倒序，在B中操作队列的头，Bhead
    CQueue() {
    }
    
    void appendTail(int value) {//在队尾添加元素=直接压入A栈
            stackA.push(value);   
    }
    
    int deleteHead() {          //在队头删除元素=在倒序栈B中，stackB.pop();
        if(stackB.size() != 0) {//B不为空，直接删除队列的头即可
        Bhead=stackB.top();     //不能用stackB.length()!=0;
        stackB.pop();
        return Bhead;
        }

        else{                               //B为空，则从A中取值
            if(stackA.size()==0){return -1;}//A为空，返回-1
            while(stackA.size()!=0){        //A不为空，倒序压入栈B
                stackB.push(stackA.top());
                stackA.pop();
            }
            Bhead=stackB.top();//
            stackB.pop();
            return Bhead;
        }

    }
};
```