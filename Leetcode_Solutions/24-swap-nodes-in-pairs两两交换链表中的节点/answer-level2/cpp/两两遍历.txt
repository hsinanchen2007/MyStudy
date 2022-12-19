### 解题思路
虽然是两两交换，但是需要三个node变量来记录。prevnode用于记录上一对交换后的节点中的后节点的next。如果是奇数的情况就要直接指向first而非second

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
    ListNode* swapPairs(ListNode* head) {
        if (NULL == head || NULL == head->next) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        head = second;
        ListNode* prevnode = new ListNode(0);
        while (NULL != first) {
            second = first->next;
            prevnode->next = second;
            if (NULL == second) {
                prevnode->next = first;
                break;
            }
            prevnode = first;
            first->next = second->next;
            second->next = first;
            first = first->next;
        }
        return head;
    }
};
```