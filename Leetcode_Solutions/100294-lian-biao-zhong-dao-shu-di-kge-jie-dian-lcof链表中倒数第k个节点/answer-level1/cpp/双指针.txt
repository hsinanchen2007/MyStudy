快慢指针，指针A先让指针Bk个，然后指针B跑到终点，指针A就是我们的目标了。
```
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode*h=head;
        for(int i=0;i<k;i++)
            h=h->next;
        while(h){
            h=h->next;
            head=head->next;
        }
        return head;
    }
};
```