首先快慢双指针找到中间节点，并分割成两个链表；然后逆置第二个链表；最后合并两个链表。
```
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *p, *q, H(-1);
        for(H.next=head, p=q=&H; p && (p=p->next); p=p->next, q=q->next);
        head=q->next;
        q->next=NULL;
        for(p=NULL; head; swap(head,p))
            swap(p,head->next);
        for(q=H.next, head=&H; p && q;){
            head=head->next=q;
            q=q->next;
            head=head->next=p;
            p=p->next;
        }
        head->next=(p?p:q);
    }
};
```
