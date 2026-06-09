快慢指针

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
  // 1 2 3 4 5 6
  // 11
  // 23
  // 35
  // 4 null
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head,*slow = head;
        while(slow != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == NULL) break;
        }
        return slow;
    }
};
```
