先让快指针走K步，然后快指针和慢指针一起走，快指针走到结尾为止

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *slow=head;
        ListNode *fast=head;
        for(int i=0;i<k;i++)
        {
            fast=fast->next;
        }
        while(fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};
```
