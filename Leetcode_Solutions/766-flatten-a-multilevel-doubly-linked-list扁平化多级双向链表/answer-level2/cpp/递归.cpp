### 解题思路
递归

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    //递归：返回值  调用单元:如果当前节点有子链表，那么首先记录当前节点的后一个节点，然后递归到子链表，返回子链表的最后一个节点，把这个节点的下一个节点变成记录的节点，然后向下进行遍历    终止条件：当前节点为最后一个节点
    Node* exchange(Node* head)
    {
        //当前节点没有后继节点并且没有子节点的时候，直接返回
        if(head->next==nullptr && head->child==nullptr) return head;
        Node* pNode = head;
        //now指向当前链表中的最后一个节点
        Node* now = pNode;
        while(pNode!=nullptr) {
            Node* pNext = pNode->next;
            if(pNode->child!=nullptr) {
                pNode->next = pNode->child;
                pNode->child->prev = pNode;
                pNode->child = nullptr;
                Node* pre = exchange(pNode->next);
                pre->next = pNext;
                //注意空指针异常
                if(pNext!=nullptr) pNext->prev = pre;
                //有可能返回来的pre子链表就是最后一个节点
                now = pre;
            }
            if(pNext) now = pNext;
            pNode = pNext;
        }
        return now;
    }
    Node* flatten(Node* head) {
        if(head==nullptr) return head;
        exchange(head);
        return head;
    }
};
```