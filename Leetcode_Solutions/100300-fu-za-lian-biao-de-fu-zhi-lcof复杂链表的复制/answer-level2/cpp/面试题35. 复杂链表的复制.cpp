### 解题思路
    1. 把复制的结点链接在原始链表的每一对应结点后面
    2. 把复制的结点的random指针指向被复制结点的random指针的下一个结点 
    3. 拆分成两个链表，奇数位置为原链表，偶数位置为复制链表
    注意：复制链表的最后一个结点的next指针不能跟原链表指向同一个空结点NULL，
    next指针要重新赋值NULL(判定程序会认定你没有完成复制）

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
    if(!head){
            return NULL;
        } 
        //1.把复制的结点链接在原始链表的每一对应结点后面 
        Node *currNode = head;
        while(currNode != NULL){
            Node *cloneNode  = new Node(currNode->val);
            cloneNode->next = currNode->next;
            currNode->next = cloneNode;
            currNode = cloneNode->next;
        }
        //2.把复制的结点的random指针指向被复制结点的random指针的下一个结点 
        currNode = head;
        while(currNode != NULL){
            Node *nextNode = currNode->next;
            if(currNode->random){               
                nextNode->random = currNode->random->next;
            }
            currNode = nextNode->next;
        }
        //3.拆分成两个链表，奇数位置为原链表，偶数位置为复制链表
        Node *pCloneHead = head->next;
        Node *cloneNode;
        currNode = head;
        while(currNode->next != NULL){
            cloneNode = currNode->next;
            currNode->next =cloneNode->next;
            currNode = cloneNode;
        }
        return pCloneHead;
    }
};
```