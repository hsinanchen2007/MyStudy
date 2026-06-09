### 解题思路
第一次来力扣，有点不适应

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur=new ListNode(-1);
        cur->next=head;
        ListNode *first=cur,*second=cur;
        for(int i=0;i<n;i++)   
            first=first->next;
        while(first->next)
        {
            first=first->next;
            second=second->next;
        }
        second->next=second->next->next;
        return cur->next;
    }
};
```