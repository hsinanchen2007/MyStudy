### 解题思路
- 用deque模拟链表，push_back，push_front,insert,erase四个库函数完成插入和删除的操作
- STL还是厉害啊

### 代码

```cpp
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        list = {};
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < -1 || index >= list.size())
            return -1;
        return list[index];
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        list.push_front(val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        list.push_back(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index<0)
            list.push_front(val);
        else if(index > list.size())
            list.push_back(val);
        else
            list.insert(list.begin() + index,val);
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<list.size())
            list.erase(list.begin() + index);
    }
private:
    deque<int> list;
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