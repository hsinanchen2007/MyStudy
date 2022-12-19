### 解题思路


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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* p = pre;
        while(p)
        {
            ListNode* q = p->next;
            int cnt = 0;
            while(q)
            {
                cnt += q->val;
                if(cnt == 0)
                    p->next = q->next;
                q = q->next;
            }
            p = p->next;
        }
        return pre->next;
    }
};
```