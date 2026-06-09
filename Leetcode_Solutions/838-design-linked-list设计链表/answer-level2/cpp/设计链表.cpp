### 算法分析
1. 使用单链表节点，使用length记录链表长度,使用head哨兵节点作为头节点的前置节点
2. 添加节点的时候++length，移除节点的时候--length
### 复杂度分析
+ 时间复杂度
1. get(index)：O(index)
2. addAtHead(val)：O(1)
3. addAtTail(val)：O(n)
4. addAtIndex(index, val)：O(index)
5. deleteAtIndex(index)：O(index)
+ 空间复杂度：都是O(1)
### 源码
```C++ []
struct SinglyNode
{
    int val;
    SinglyNode* next;
    SinglyNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        mHead = new SinglyNode(-1);
        mLenth = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= mLenth)
            return -1;

        SinglyNode* node = mHead;

        for (int i = 0; i <= index; i++)
        {
            node = node->next;
        }        

        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(mLenth, val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > mLenth)
            return;
            
        if (index < 0)
            index = 0;
        
        SinglyNode* preNode = mHead;

        for (int i = 0; i < index; i++)
        {
            preNode = preNode->next;
        }        

        SinglyNode* node = new SinglyNode(val);
        node->next = preNode->next;
        preNode->next = node;

        ++mLenth;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= mLenth)
            return;

        SinglyNode* preNode = mHead;

        for (int i = 0; i < index; i++)
        {
            preNode = preNode->next;
        }        

        preNode->next = preNode->next->next;

        --mLenth;
    }

private:
    SinglyNode* mHead;
    int mLenth;
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