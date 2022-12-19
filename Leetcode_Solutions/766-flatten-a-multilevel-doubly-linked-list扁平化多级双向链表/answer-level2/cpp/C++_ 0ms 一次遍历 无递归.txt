我寻思这不就是每遇到一个child就把它并到队伍里然后head = head->next吗？
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
public:
    Node* flatten(Node* head) {
        Node* h = head;
        while(head){
            if(head->child != NULL){
                Node *childmember = head->child;
                while(childmember->next != NULL) childmember = childmember->next;
                childmember->next = head->next;
                if(head->next) head->next->prev = childmember;
                head->next = head->child;
                head->child = NULL;
                head->next->prev = head;
            }
            head = head->next;
        }
        return h;
    }
};
```
