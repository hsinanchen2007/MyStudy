### 解题思路
此处撰写解题思路
先将链表每个元素复制并连接在该元素后面，则复制后的元素的random等于其前一个元素的random->next(random==NULL为特殊情况)，最后再将链表的重复元素拆解变成两条链表
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
        if(head==NULL) return NULL;
        Node* tmp=head, * newhead;
        while(tmp){
            Node* node=(Node*)malloc(sizeof(Node));
            node->val=tmp->val;
            node->next=tmp->next;
            tmp->next=node;
            tmp=tmp->next->next;
        }
        tmp=head;
        while(tmp!=NULL){
            if(tmp->random==NULL) tmp->next->random=NULL;
            else
             tmp->next->random=tmp->random->next;
            tmp=tmp->next->next;
        }
        newhead=head->next;
        tmp=head->next;
        while(tmp->next!=NULL){
            
            head->next=tmp->next;
            tmp->next=tmp->next->next;
            head=head->next;
            tmp=tmp->next;
        }
        head->next=NULL;
        return newhead;
    }
};
```