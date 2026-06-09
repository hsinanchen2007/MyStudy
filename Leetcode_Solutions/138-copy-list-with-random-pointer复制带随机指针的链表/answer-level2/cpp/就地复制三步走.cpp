可以在原链表中间插入新复制的节点，即在每个原节点的next处插入新节点。
第一步，复制新节点，复制next；
第二步，复制random；
第三步，将新节点组成新链表，同时恢复旧链表。
```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        for(Node* p=head; p; p=p->next->next)
            p->next = new Node(p->val, p->next, NULL);
        for(Node* p=head; p; p=p->next->next)
            if(p->random) p->next->random = p->random->next;
        Node H(-1,NULL,NULL);
        for(Node *p=head, *q=&H; p;){
            q=q->next=p->next;
            p=p->next=q->next;
        }
        return H.next;
    }
};
```
