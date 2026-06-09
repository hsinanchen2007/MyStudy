```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* jhead=head;//奇数链头
        ListNode* ohead=head->next;//偶数链头
        ListNode* o=ohead;//最初的偶数链头
        while(ohead&&ohead->next)//依次将后面的元素附在奇偶表头之后
        {
            jhead->next=ohead->next;
            jhead=jhead->next;
            ohead->next=jhead->next;
            ohead=ohead->next;
        }
        jhead->next=o;//最后的奇数链尾指向最初的偶数链头
        return head;
    }
};
```
