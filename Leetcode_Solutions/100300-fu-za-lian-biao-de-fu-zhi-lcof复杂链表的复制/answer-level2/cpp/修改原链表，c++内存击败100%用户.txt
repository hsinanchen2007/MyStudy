### 解题思路
    先在每个原链表后面增加一个链表，然后再次循环复制每个链表的随机指针，最后分离两个链表;

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
        if(!head)return head;
        Node* phead=head;
        while(phead){
            Node* temp=new Node(phead->val);
            Node* p=phead->next;
            phead->next=temp;
            temp->next=p;
            phead=p;
        }
        phead=head;
        while(phead){
            Node* t=phead->next;
            if(phead->random)
                t->random= phead->random->next;
            else
                t->random=NULL;
            phead=t->next;
        }
        phead=head;
        Node* res = head->next;
        Node* pres = head->next;
        while(res&&res->next){
            Node* old = res->next;
            Node* newp = old->next;
            phead->next=old;
            res->next=newp;
            phead = old;
            res = newp;
        }
        if(phead)
            phead->next=nullptr;
        
        return pres;
    }
};
```