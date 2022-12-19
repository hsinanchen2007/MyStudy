用哨兵节点当栈底写一个栈就行了，另一个指针用于指向下面最小的值。

```
class MinStack {
public:
    /** initialize your data structure here. */
    struct StackNode{
        int v;
        StackNode *after,*minLink;
        StackNode():after(nullptr),minLink(nullptr){}
        ~StackNode(){}
    }*StackBottom,*StackTop,*tmp;
    MinStack():StackBottom(new StackNode),StackTop(StackBottom) {

    }
    
    void push(int x) {
        tmp=new StackNode;
        tmp->after=StackTop;
        tmp->v=x;
        if(StackTop==StackBottom){
            tmp->minLink=tmp;
        }else{
            tmp->minLink=x<StackTop->minLink->v?tmp:StackTop->minLink;
        }
        StackTop=tmp;
    }
    
    void pop() { // assume this operation always valid
        tmp=StackTop->after;
        delete StackTop;
        StackTop=tmp;
    }
    
    int top() {
        return StackTop->v;
    }
    
    int min() {
        return StackTop->minLink->v;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```
