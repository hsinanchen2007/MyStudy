## 思路一：利用deque
### 代码
```c++
class MyLinkedList {
    deque<int> data;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        return (index >= 0 && index < data.size()) ? data[index] : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        data.push_front(val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        data.push_back(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index >= 0 && index <= data.size()) {
            data.insert(data.begin() + index, val);
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= 0 && index < data.size()) {
            data.erase(data.begin() + index);
        }
    }
};
```

## 思路二：利用链表（击败99.9%）
### 代码
```c++
class MyLinkedList {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    ListNode *head = nullptr;
    int size;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new ListNode(0);
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode *tmp = head;
        for (int i = 0; i < index; ++i) {
            tmp = tmp->next;
        }        
        return tmp->next->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {        
        ListNode *tmp = new ListNode(val);
        tmp->next = head->next;
        head->next = tmp;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *tmp = new ListNode(val);
        ListNode *cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = tmp;
        ++size;

    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        ListNode *tmp = head;
        for (int i = 0; i < index; ++i) {
            tmp = tmp->next;
        }
        ListNode *node = new ListNode(val);
        node->next = tmp->next;
        tmp->next = node;
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= 0 && index < size) {
            ListNode *pre = head;
            for (int i = 0; i < index; ++i) {
                pre = pre->next;                
            }
            ListNode *deleted = pre->next;
            ListNode *next = deleted->next;
            pre->next = next;
            --size;
            deleted->next = nullptr;
            delete deleted;
        }
    }
};
```


