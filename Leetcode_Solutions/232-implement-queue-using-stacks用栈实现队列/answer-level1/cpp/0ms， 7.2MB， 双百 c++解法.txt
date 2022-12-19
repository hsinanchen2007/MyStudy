### 解题思路
两个栈实现队列

### 代码

```cpp
//
// Created by 张麒 on 2020/4/3.
//

class MyQueue {
    struct Node {
        int val;
        Node *next;
        Node(int _val) : val(_val), next(nullptr) {}
        Node() : next(nullptr) {}
    };
    Node *in_head = new Node();
    Node *out_head = new Node();
    int in_size = 0;
    int out_size = 0;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        in_push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if((in_size+out_size) > 0){
            if(out_size == 0){
                removeFromInToOut();
            }
            return out_pop();
        }
        return -1;

    }
    void removeFromInToOut(){
        while(in_size > 0){
            out_push(in_pop());
        }
    }

    /** Get the front element. */
    int peek() {
        if((in_size+out_size) > 0){
            if(out_size == 0){
                removeFromInToOut();
            }
        } 
        if(out_head->next != nullptr){
            return out_head->next->val;
        }
        return -1;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return in_size+out_size == 0;
    }
private:
    void in_push(int x) {
        Node *cur = in_head;
        Node *next = cur->next;
        Node *newNode = new Node(x);
        newNode->next = next;
        cur->next = newNode;
        in_size++;
    }

    void out_push(int x) {
        Node *cur = out_head;
        Node *next = cur->next;
        Node *newNode = new Node(x);
        newNode->next = next;
        cur->next = newNode;
        out_size++;
    }
    int in_pop() {
        Node *cur = in_head;
        if(cur->next == nullptr){
            return -1;
        }
        Node *tmp = cur->next;
        cur->next = tmp->next;
        int tmp_val = tmp->val;
        delete (tmp);
        in_size--;
        return tmp_val;
    }
    int out_pop() {
        Node *cur = out_head;
        if(cur->next == nullptr){
            return -1;
        }
        Node *tmp = cur->next;
        cur->next = tmp->next;
        int tmp_val = tmp->val;
        delete (tmp);
        out_size--;
        return tmp_val;
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
```