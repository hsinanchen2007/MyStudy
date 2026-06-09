```cpp
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

        if (head == NULL || k <= 0)  
            return NULL;
        
        ListNode *p = head;
        ListNode *q = head;
        for (int i = 0; i < k - 1; i ++) {
            if (p->next)
                p = p->next;
            else
                return NULL;    // k大于链表总长
        }
        while (p->next) {
            p = p->next;
            q = q->next;
        }

        return q;
        
    }
};
```