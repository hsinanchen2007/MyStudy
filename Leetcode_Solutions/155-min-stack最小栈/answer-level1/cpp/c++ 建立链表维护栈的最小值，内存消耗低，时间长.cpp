### 解题思路
建立了一个链表从小到大维护栈的最小值，可以以常数时间检索最小值，但是每次push()、pop()维护链表的时间太长了，所以最后内存消耗低，但是执行时间长。
![image.png](https://pic.leetcode-cn.com/9c7b137c00ff3a49974337c0ed86c816926cde8363cb9ee6a9aac321377f85bf-image.png)


### 代码

```cpp
struct ListNode_fgy{
    int val;
    ListNode_fgy* next;
    ListNode_fgy(int _val):val(_val),next(nullptr){}
};

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> st;
    int imin;
    ListNode_fgy* min_list;
    MinStack() {
        imin=INT_MAX;
        min_list=new ListNode_fgy(-1);
        st={};
    }

    void push(int x) {
        st.push_back(x);
        ListNode_fgy* p=min_list;
        while(p->next!=nullptr&&p->next->val<x)
            p=p->next;
        ListNode_fgy* new_node=new ListNode_fgy(x);
        new_node->next=p->next;
        p->next=new_node;
    }

    void pop() {
        if(st.size()<=0)
            return ;
        ListNode_fgy* p=min_list->next;
        ListNode_fgy* pre=min_list;
        while(p->val!=top())
        {
            p=p->next;
            pre=pre->next;
        }
        pre->next=p->next;
        delete p;
        st.pop_back();
    }

    int top() {
        if(st.size()==0)
            return -1;
        return st[st.size()-1];
    }

    int getMin() {
        return min_list->next->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```