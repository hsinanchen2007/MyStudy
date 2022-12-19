### 解题思路
效率不高的双向链表，不过一眼看不出特别的瓶颈点

### 代码

```cpp
class MyLinkedList {
private:
    int val;
    MyLinkedList *prev;
    MyLinkedList *next;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->prev = this;
        next = this;
    }
    
    bool isEnd(MyLinkedList *node) {
        if (node == this)
            return true;
        else
            return false;
    }
    
    void print() {
        MyLinkedList *cur = this->next;
        while (!isEnd(cur)) {
            cout << cur->val << "->";
            cur = cur->next;
        }
        cout << endl;
    }
    
    int getLen() {
        int len = 0;
        MyLinkedList *cur = this->next;
        while (!isEnd(cur)) {
            len++;
            cur = cur->next;
        }
        return len;
    }
    
    MyLinkedList *getNode(int index) {
        MyLinkedList *cur = this->next;
        
        for (int i = 0; i < index; i++) {
            if (isEnd(cur))
                return NULL;
            cur = cur->next;
        }
        
        if (isEnd(cur))
            return NULL;
        else
            return cur;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        MyLinkedList *cur = getNode(index);
        if (cur == NULL)
            return -1;
        else
            return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyLinkedList *node = new MyLinkedList();
        node->val = val;
        node->prev = this;
        node->next = this->next;
        this->next->prev = node;
        this->next = node;
        //print();
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyLinkedList *node = new MyLinkedList();
        node->val = val;
        node->next = this;
        node->prev = this->prev;
        this->prev->next = node;
        this->prev = node;
        //print();
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        MyLinkedList *cur = getNode(index);
        if (cur == NULL) {
            if (index == getLen())
                cur = this;
            else
                return;
        }
        MyLinkedList *node = new MyLinkedList();
        node->val = val;
        node->prev = cur->prev;
        node->next = cur;
        cur->prev->next = node;
        cur->prev = node;
        //print();
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        MyLinkedList *cur = getNode(index);
        if (cur != NULL) {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
            //print();
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```