被 `addAtIndex` 这个方法里的 `index` 负数坑了，开始以为负数代表逆向遍历，结果还是错，看了评论区才明白了负数的真谛。

```cpp []
struct DListNode {
    int val;
    DListNode *prev, *next;
    DListNode(int val) : val(val), prev(nullptr), next(nullptr) {}
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (auto node = getNode(index)) {
            return node->val;
        }
        
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto node = new DListNode(val);
        size_++;
        
        if (head_ == nullptr) {
            head_ = node;
            tail_ = node;
        } else {
            node->next = head_;
            head_->prev = node;
            head_ = node;   
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto node = new DListNode(val);
        size_++;
        
        if (tail_ == nullptr) {
            head_ = node;
            tail_ = node;
        } else {
            tail_->next = node;
            node->prev = tail_;
            tail_ = node;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size_) return;
        if (index == size_) {
            addAtTail(val);
            return;
        }
        
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        
        auto node = new DListNode(val);
        auto next = getNode(index);
        
        node->next = next;
        node->prev = next->prev;
        next->prev->next = node;
        next->prev = node;
        
        size_++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (auto node = getNode(index)) {
            if (node == head_) {
                head_ = head_->next;
                if (head_ != nullptr) head_->prev = nullptr;
                node->next = nullptr;
            }
            
            if (node == tail_) {
                tail_ = tail_->prev;
                if (tail_ != nullptr) tail_->next = nullptr;
                node->prev = nullptr;
            }
            
            if (node->next != nullptr) node->next->prev = node->prev;
            if (node->prev != nullptr) node->prev->next = node->next;

            delete node;
            size_--;
        }
    }
    
private:
    DListNode *getNode(int index) {
        if (index >= size_ || index < 0) return nullptr;
        
        DListNode *node;
        int i;
        
        if (size_ - index - 1 < index) {
            i = size_ - index - 1;
            node = tail_;
            while (i-- > 0) {
                node = node->prev;
            }
        } else {
            i = index;
            node = head_;
            while (i-- > 0) {
                node = node->next;
            }
        }
        
        return node;
    }
    
private:
    DListNode *head_;
    DListNode *tail_;
    int size_;
};
```