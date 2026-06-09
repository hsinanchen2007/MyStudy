

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* fast = head, * slow = head, * cur = head;
        int cnt = 0;
        while(cur){
            cur = cur->next;
            cnt++;
        }
        int step = k%cnt;
        while(step--){
            fast = fast->next;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        ListNode* res = slow->next;
        slow->next = NULL;
        return res;
    }
};
```
