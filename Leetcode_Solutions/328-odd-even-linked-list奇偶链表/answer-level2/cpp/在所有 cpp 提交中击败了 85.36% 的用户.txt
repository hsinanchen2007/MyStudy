```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next ||!head->next->next)
            return head;
        ListNode* oddhead=head;
        ListNode* evenhead=head->next;
        ListNode* evenhead_copy=head->next;
        ListNode* temp;
        while(evenhead && evenhead->next){
            temp=evenhead->next;
            evenhead->next=temp->next;
            evenhead=evenhead->next;
            oddhead->next=temp;
            oddhead=oddhead->next;
        }
        oddhead->next=evenhead_copy;
        return head;

    }
};
```

奇偶双指针交替连接形成新链表，最后把偶链表接到奇链表末尾。
