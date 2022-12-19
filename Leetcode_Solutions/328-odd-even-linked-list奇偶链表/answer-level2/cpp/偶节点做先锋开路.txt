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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        ListNode *even_head = head->next;
        ListNode *odd = head, *even = head->next;

        while (true) {
            if (even == NULL || even->next == NULL) {
                odd->next = even_head;
                return head;
            }
            odd->next = even->next;
            odd = even->next;
            even->next = odd->next;
            even = odd->next;
        }

        return NULL;
    }
};
```