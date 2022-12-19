### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    typedef struct Node{
        int val;
        int min;
        Node *next;
        Node(int val, int min, Node* next){
            this->val = val;
            this->min = min;
            this->next = next;
        }
    }node;

    node *head;

    MinStack() {
        head = NULL;
    }
    
    void push(int x) {
        if(head == NULL){
            head = new Node(x, x, NULL);
        }else{
            node *tmp = new Node(x, x<head->min?x:head->min, head);
            head = tmp;
        }
    }
    
    void pop() {
        if(head!=NULL){
            head = head->next;
        }
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        if(head!=NULL){
            return head->min;
        }else{
            return -1;
        }

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