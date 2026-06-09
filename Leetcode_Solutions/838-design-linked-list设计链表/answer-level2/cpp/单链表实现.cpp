c++实现：
48ms，18.9MB，应该还可以优化，后续再优化。
```
class MyLinkedList {
private:
    struct SinglyListNode {
        int val;
        SinglyListNode *next;
        SinglyListNode(int x) : val(x), next(NULL) {}
    }; 
    SinglyListNode* head;
    int size;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        // head是指针，需要初始化为NULL
        head = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        
        SinglyListNode* tmp;
        tmp = head;
        
        int count = 0;
        while(tmp -> next != NULL) {
            if(count != index) {
                tmp = tmp -> next;
                count++;
            }
            else {
                return tmp -> val;
            }
        }
        return tmp -> val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        SinglyListNode* cur;
        cur = new SinglyListNode(val);
        if(size != 0)  {
            cur -> next = head;
            head = cur;
            size++;
        }
        else {
            head = cur;
            size++;
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        SinglyListNode* tmp;
        tmp = head;
        while(tmp -> next != NULL) {
            tmp = tmp -> next;
        }
        SinglyListNode* cur;
        cur = new SinglyListNode(val);
        if(size != 0) {
            tmp -> next = cur;
        }
        else {
            head = cur;
        }
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index <= 0) {
            addAtHead(val);
        }
        else if(index > 0 && index < size) {
            SinglyListNode* cur;
            cur = new SinglyListNode(val);
            
            SinglyListNode* tmp;
            tmp = head;
            
            SinglyListNode* prev;
            prev = NULL;
            SinglyListNode* next;
            next = tmp;
            
            int count = 0;
            while(tmp -> next != NULL) {
                if(count != index) {
                    prev = tmp;
                    next = tmp -> next;
                    tmp = tmp -> next;
                    count++;
                }
                else{
                    break;
                }
            }
            cur -> next = next;
            prev -> next = cur;
            size++;
        }
        else if(index == size){
            addAtTail(val);
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index == 0) {
            head = head -> next;
            size--;
        }
        else if(index == size - 1) {
            SinglyListNode* tmp;
            tmp = head;
            while(tmp -> next -> next != NULL) {
                tmp = tmp -> next;
            }
            tmp -> next = NULL;
            size--;
        }
        else if(index > 0 && index < size) {
            SinglyListNode* tmp;
            tmp = head -> next;
            SinglyListNode* prev;
            prev = head;
            
            int count = 1;
            while(tmp -> next != NULL) {
                if(count != index) {
                    prev = tmp;
                    tmp = tmp -> next;
                    count++;
                }
                else {
                    prev -> next = tmp -> next;
                    break;
                }
            }
            size--;
        }
    }
};
```
