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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || (head != NULL && head->next == NULL))
            return head;
        ListNode* p, *q;
        p = NULL;
        q = head;
        while(q != NULL)
        {
            ListNode* next = q->next;
            q->next = p;
            p = q;
            q = next;
        }
        return p;
    }
};
```