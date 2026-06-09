### 解题思路
链表实现
注意：前向声明的类或结构体只能用指针或者引用

### 代码

```cpp
struct Node
{
    int val;
    int min_node;
    Node* next;
    Node(int min):val(0),min_node(min),next(NULL) {}
    Node(int x,int min,Node* next):val(x),min_node(min),next(next) {}
};
class MinStack
{
private:
    Node* head;
public:
    /** initialize your data structure here. */
    MinStack()
    {
        head = new Node(INT_MAX);
    }

    void push(int x)
    {
        head = new Node(x,min(x,head->min_node),head);
    }

    void pop()
    {
        head = head->next;
    }

    int top()
    {
        return head->val;
    }

    int getMin()
    {
        return head->min_node;
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