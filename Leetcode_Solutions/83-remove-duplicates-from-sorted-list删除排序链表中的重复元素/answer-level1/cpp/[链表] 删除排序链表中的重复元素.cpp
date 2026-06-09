见代码
```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ret = head;
        while(head!=NULL && head->next != NULL) {
            if(head->next->val == head->val) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        return ret;
    }
};
```