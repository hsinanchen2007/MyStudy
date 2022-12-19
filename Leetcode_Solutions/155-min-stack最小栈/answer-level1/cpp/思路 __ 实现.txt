# 思路
可以想到的是 每次push时要存储 此时（插入该节点后） 的最小值 这样getmin时候才会o(1)
也就是空间换时间

# 实现
大体上可有以下几种实现方式
    1.栈结点除val，next外还保存当前结点push后的最小值
    2.栈结点除val，next外还保存一个指针指向当前最小值结点 
    3.辅助栈  双栈   主栈push时 辅助栈push当前最小值(若有必要的话)
                    主栈pop时 仅当两栈顶相同时辅助栈出栈
    4.双push 每次push时先push此时最小值入栈 再push当前val
            相应的 pop时也pop两次
    5.数学方法 设置一个空间存储当前最小值，栈push最小值与当前val的差值
                                通过计算可推前一个min值

1、2、4方法也等同于3每次都push主栈的值(而非只push当前最小值）
故真正效率的是方法3和方法5

# 1 栈结点加min
```
class MinStack {
public:
    /** initialize your data structure here. */
    struct StackNode{
        int val;
        int min;
        StackNode* next;
        StackNode(int _val,StackNode* _next = NULL):val(_val),min(_val),next(_next){}
    };
    StackNode* head;
    MinStack() {
        head = new StackNode(0);
    }
    
    void push(int x) {
        StackNode* sumire = new StackNode(x,head->next);
        if(head->next && x > head->next->min)
        {
            sumire->min = head->next->min;
        }
        head->next = sumire;
    }
    
    void pop() {
        StackNode* sumire= head->next;
        if(sumire)
        {
            head->next = sumire->next;
            delete sumire;
        }
    }
    
    int top() {
        int top = 0;
        if(head->next)
        {
            top = head->next->val;
        }
        return top;
    }
    
    int getMin() {
        int min = 0;
        if(head->next)
        {
            min = head->next->min;
        }
        return min;
    }
};
```
# 2 栈结点加ptr
```
class MinStack {
public:
    /** initialize your data structure here. */
    struct Node{
        int val;
        Node* next;
        Node* min;
        Node(int _val,Node* _next = NULL,Node* _min = NULL)
        :val(_val),next(_next),min(_min){}
    };
    Node* head;
    MinStack() {
        head = new Node(0);
    }
    
    void push(int x) {
        Node* sumire = new Node(x,head->next);
        if(head->next)
        {
            if(x > head->next->min->val)
            {
                sumire->min = head->next->min;
            }
            else
            {
                sumire->min = sumire;
            }
        }
        else{
            sumire->min = sumire;
        }
        head->next = sumire;
    }
    
    void pop() {
        Node* sumire = head->next;
        if(head->next)
        {
            head->next = sumire->next;
            delete sumire;
        }
    }
    
    int top() {
        int top = 0;
        if(head->next)
        {
            top = head->next->val;
        }
        return top;
    }
    
    int getMin() {
        int min;
        if(head->next)
        {
            min = head->next->min->val;
        }
        return min;
    }
};
```
# 3 辅助栈
```
class MinStack {
public:
    /** initialize your data structure here. */
    struct Node{
        int val;
        Node* next;
        Node(int _val,Node* _next = NULL):val(_val),next(_next){}
    }; 

    Node* head;
    MinStack() {
        head = new Node(0);
    }
    
    void push(int x) {
        int tmin = 0;
        if( head->next && x > head->next->val)
        {
            tmin =  head->next->val;
        }
        else
        {
            tmin = x;
        }
        Node* Sumire = new Node(x,head->next);
        Node* MinNode = new Node(tmin,Sumire);
        head->next = MinNode;
    }
    
    void pop() {
        Node* sumire = head->next;
        if(sumire) 
        {
            head->next = sumire->next->next;
            delete sumire->next;
            delete sumire;
        }
    }
    
    int top() {
        int top = 0;
        if(head->next)
        {
            top = head->next->next->val;
        }
        return top;
    }
    
    int getMin() {
        int min = 0;
        if(head->next)
        {
            min = head->next->val;
        }
        return min;
    }
};
```
# 4 双push
```
class MinStack {
public:
    /** initialize your data structure here. */
    int stack[20000];
    int _top = -1;
    MinStack() {

    }
    
    void push(int x) {
        if(_top == -1)
        {
            stack[++_top] = x;
            stack[++_top] = x;
        }
        else
        {
            int min = stack[_top];
            if(min < x)
            {
                stack[++_top] = x;
                stack[++_top] = min;
            }
            else{
                stack[++_top] = x;
                stack[++_top] = x;
            }
        }
    }
    
    void pop() {
        if(_top != -1)
        {
            _top -= 2;
        }
    }
    
    int top() {
        if(_top!= -1)
        {
            int sumire = stack[_top-1];
            return sumire;
        }
        return -1;
    }
    
    int getMin() {
        if(_top!= -1)
        {
            int sumire = stack[_top];
            return sumire;
        }
        return -1;
    }
};
```
# 5 数学方法 （待更）


