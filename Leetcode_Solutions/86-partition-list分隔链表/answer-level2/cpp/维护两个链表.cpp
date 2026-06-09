维护一个小于x的链表和一个大于x的链表，然后合并两个链表即可
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
    ListNode* partition(ListNode* head, int x) {
        // Nice, AC this problem only one attempt
        // 1 4 3 2 5 2  x = 3
        auto dummy1 = new ListNode(-1);        
        auto dummy2 = new ListNode(-1);        
        auto less = dummy1, greater = dummy2, p = head;
        
        // less:dummy1->1->2->2 greater:dummy2->4->3->5
        while(p) {
            if (p->val < x) {
                less->next = p;
                less = less->next;
            } else {
                greater->next = p;
                greater = greater->next;
            }
            p = p->next;
        }
    
        // Merge two lists
        less->next = dummy2->next;
        greater->next = NULL;

        return dummy1->next;
    }
};

```
