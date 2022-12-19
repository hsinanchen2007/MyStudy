- 时间复杂度：O(n)
- 空间复杂度：O(1)
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
        ListNode* slow = head;
        ListNode* fast = head;
        
        int i = 1;
        while(fast) {
            if(i > k) slow = slow->next;
            fast = fast->next;
            i++;
        }
        
        return slow;
    }
};
```

