### 解题思路
C++递归

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
    ListNode * reverseBegin(ListNode * head, ListNode * n)
    {
        ListNode * p;
        if(n == NULL) return head;
        else 
        {
            p = n->next;
            n -> next = head;
            return reverseBegin(n, p); 
        }
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode * p = head->next;
        head ->next = NULL;
        return reverseBegin(head, p);
    }
};
```