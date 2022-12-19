解题思路：官方题解


```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur=head;
        while(cur!=NULL&&cur->next!=NULL)
        {
            if(cur->val==cur->next->val)
            {
                cur->next=cur->next->next;
            }
            else
            {
                cur=cur->next;
            }
        }
        return head;
    }
};
```
