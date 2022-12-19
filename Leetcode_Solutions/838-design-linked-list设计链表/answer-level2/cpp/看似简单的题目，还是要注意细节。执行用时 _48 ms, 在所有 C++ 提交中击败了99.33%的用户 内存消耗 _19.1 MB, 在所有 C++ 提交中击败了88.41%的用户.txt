```
//ListNode力扣已经定义
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class MyLinkedList {
private:
    ListNode *head_ = nullptr;
    ListNode *tail_ = nullptr;
    int size_ = 0;
public:
    /** Initialize your data structure here. */
    MyLinkedList(){
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index > size_-1 || size_ == 0) return -1;
        auto cur = head_;
        for(int i = 0;i < index;++i)
            cur = cur->next;
        return cur->val;//前面判断过index的有效性了，这里可以放心return
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto cur = new ListNode(val);
        cur->next = head_;
        head_ = cur;
        if(!tail_) tail_ = cur;//判断尾节点是否为空
        ++size_;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto cur = new ListNode(val);
        if(tail_)
            tail_->next = cur;
        tail_ = cur;
        if(!head_)//判断头是否为空
            head_ = cur;
        cur->next = nullptr;
        ++size_;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size_)  return;
        if(index <= 0)      return addAtHead(val);
        if(index == size_)  return addAtTail(val);
        //其他情况就添加到index之前,例如（1,2）,则插入为新的1下标
        auto pre = head_;
        for(int i = 0;i < index-1;++i){
                pre = pre->next;
        }
        auto tmp = new ListNode(val);
        tmp->next = pre->next;
        pre->next = tmp;
        ++size_;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index > size_-1 || size_ == 0) return;
        if(index == 0){
            auto tmp = head_;
            head_ = head_->next;
            --size_;
            delete tmp;
            tmp = nullptr;
            return;
        }
        auto pre = head_;
        for(int i = 0;i < index-1;++i){
            pre=pre->next;
        }
        auto tmp = pre->next;
        if(pre->next == tail_){//注意是否有动到尾指针
            tail_ = pre;
            pre->next = nullptr;
        }else{
            pre->next = pre->next->next;
        }
        delete tmp;
        tmp = nullptr;
        --size_;
    }
};
```
