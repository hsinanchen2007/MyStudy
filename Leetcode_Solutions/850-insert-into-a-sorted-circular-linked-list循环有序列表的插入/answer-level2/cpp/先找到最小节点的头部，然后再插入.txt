```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node * curr = NULL;
        Node * next = NULL;
        Node * realHead = NULL;
        
        if(!head){
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        
        /*find the real head*/
        curr = head;
        next = head->next;
        while(curr->val <= next->val){
            curr = curr->next;
            next = next->next;
            if(curr == head){
                break;
            }
        }
        realHead = next;
                
        /*find the key*/
        while(next->val < insertVal){
            curr = next;
            next = next->next;
            if(next == realHead){
                break;
            }
        }
                    
        /*link*/
        curr->next = new Node(insertVal);
        curr = curr->next;
        curr->next = next;
        
        return head;
    }
};
```