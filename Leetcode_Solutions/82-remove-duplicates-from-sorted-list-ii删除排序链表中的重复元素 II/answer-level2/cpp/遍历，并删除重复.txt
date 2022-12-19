```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode n(0);
        ListNode* pre = &n, *tmp;
        pre->next = head;
        int v;

        while(head != NULL)
        {
            if(head->next != NULL && head->next->val == head->val)
            {
                v = head->val;
                while(head!=NULL && head->val == v)
                {
                    tmp = head;
                    head = head->next;
                    delete tmp;
                }
                pre->next = head;
            }
            else
            {
                pre = head;
                head = head->next;
            }
        }
        return n.next;
    }
};
```
