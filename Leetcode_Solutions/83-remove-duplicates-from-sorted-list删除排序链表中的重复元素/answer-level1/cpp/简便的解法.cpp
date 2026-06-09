设一个指针p=head，当p不为空时，如果p的val=p的next域的val，那就删掉p的next域就好了，不然的话就后移p指针

```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while (p) {
            if (p->next && p->val == p->next->val) p->next = p->next->next;
            else p = p->next;
        }
        return head;
    }
};
```