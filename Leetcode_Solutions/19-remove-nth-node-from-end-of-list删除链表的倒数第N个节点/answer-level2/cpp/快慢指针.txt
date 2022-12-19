### 解题思路
快慢指针

### 代码

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* preSlow=slow;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        while(fast!=NULL)
        {
            fast=fast->next;
            preSlow=slow;
            slow=slow->next;
        }
        if(slow==head)
        return head->next;
        preSlow->next=preSlow->next->next;
        return head;
    }
};
```