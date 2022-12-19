双指针寻找链表中间节点，将链表分割成两个链表h1,h2，然后递归分割，直到不可分（链表为空或只有一个节点），递归归并。
```
class Solution {
    ListNode* mergeList(ListNode *h1, ListNode *h2){
        ListNode *p, H(-1);
        for(p=&H; h1 && h2;){
            if(h1->val < h2->val){
                p=p->next=h1;
                h1=h1->next;
            }
            else{
                p=p->next=h2;
                h2=h2->next;
            }
        }
        p->next=(h1?h1:h2);
        return H.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode *p, H(-1);
        for(H.next=head, p=head=&H; p && p->next; head=head->next)
            p=p->next->next;
        p=head->next;
        head->next=NULL;
        return mergeList(sortList(H.next),sortList(p));
    }
};
```
