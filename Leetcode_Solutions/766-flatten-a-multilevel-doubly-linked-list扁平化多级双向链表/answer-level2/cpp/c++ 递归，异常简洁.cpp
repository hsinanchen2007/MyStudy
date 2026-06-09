```
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
    Node *tail;//保存上次递归后的尾节点
public:
    Node* flatten(Node* head) {
        if(head==NULL)return NULL;
        auto cur=head;
        while(cur){
            if(cur->child){
                auto tmp=cur->next;
                cur->next=flatten(cur->child);
                if(cur->next)cur->next->prev=cur;
                cur->child=NULL;
                tail->next=tmp;
                if(tail->next)tail->next->prev=tail;
                cur=tmp;
            }else{
                tail=cur;//正确设置tail的值
                cur=cur->next;
            }
        }
        return head;
    }
};
```
