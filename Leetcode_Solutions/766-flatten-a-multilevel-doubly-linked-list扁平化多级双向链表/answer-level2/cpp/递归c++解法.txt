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
        if(!head) return NULL;
        else{
            Node* now = head;
            while(now){
                
            
                if(now->child){
                    Node* n = now->next;
                    Node* c = flatten(now->child);
                    now->child = NULL;
                    now->next = c;
                    c->prev = now;
                    while(now->next){
                        now = now->next;
                    }
                    if(n){
                        now->next = n;
                        n->prev = now;
                    }
                }
                now = now->next;
            }
        }
        return head;
    }
};
```
