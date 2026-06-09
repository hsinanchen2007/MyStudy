栈a负责输入，栈b负责输出
```
class CQueue {
    stack<int> a;
    stack<int> b;
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        a.push(value); //输入压栈a
    }
    
    int deleteHead() {
        if(b.empty()){ //当输出栈b为空时
            if(a.empty()) return -1; //若输入栈a为空则返回-1
            while(a.size()){ //否则就将栈a元素全部压入栈b
                b.push(a.top());
                a.pop();
            }
        } //栈b中元素经过压入栈a（逆序一次），压入栈b（逆序一次），即为顺序
        int tmp = b.top(); //输出栈b的栈顶元素
        b.pop();
        return tmp;  
    }
};
```
