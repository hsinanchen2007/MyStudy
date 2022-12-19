```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> m2;
        Node t(1);
        Node* temp=&t;
        Node* begin=head;
        while(head!=NULL){
            temp->next=new Node(head->val);
            temp=temp->next;
            m2[head]=temp;
            head=head->next;
        }
        temp=t.next;
        while(begin!=NULL){
            temp->random=m2[begin->random];
            begin=begin->next;
            temp=temp->next;
        }
        return t.next;
    }
};
```
