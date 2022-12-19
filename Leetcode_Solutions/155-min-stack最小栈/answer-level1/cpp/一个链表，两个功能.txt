**每个节点**包含
- 自己的数值
- 下个节点指针
- 上个节点指针
-  **如果影响了最小值，指向之前的最小值节点**（*change）

整个栈包含
- 头结点指针（头结点是个val为最大值的标志节点）
- 尾节点指针
- 最小元素节点指针

``` c++
class MinStack {
private:
    struct node {
        int val;
        node* next;
        node* pre;
        node* change;
        node(int x){val=x;}
    };
    node* head;
    node* cur;
    node* min;
public:
    MinStack() {
        head = new node(INT_MAX);
        head->pre=NULL;
        cur=head;
        min=cur;
    }
    //push的时候，如果不小于当前min节点的val
    //则将本对象的change指针指向之前的min节点
    //本节点成为新的min节点
    void push(int x) {
        cur->next=new node(x);
        cur->next->pre=cur;
        cur=cur->next;
        if(x<=min->val) 
        {
            cur->change=min;
            min=cur;
        }
    }
    
    //如果删除的本节点是当前的min节点
    //则将min指向本节点的change节点，将其设置为新的min节点
    void pop() {
        if(cur==head)return;
        if(cur==min)
        {
            min=min->change;
        }
        cur=cur->pre;
        delete cur->next;
        cur->next=NULL;
    }
    
    int top() {
        return cur->val;
    }
    
    int getMin() {
        return min->val;
    }
};
```