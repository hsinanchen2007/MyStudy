### 解题思路
此处撰写解题思路

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode* first = headA, *second = headB;
        while (first && second) {
            first = first->next, second = second->next;
        }
        if (first) {
            return CommonNode(headA, headB, first);
        }
        return CommonNode(headB, headA, second);
    }
    ListNode* CommonNode(ListNode* a, ListNode* b, ListNode* node) {
        ListNode* first = a;
        while (node) {
            node = node->next;
            first = first->next;
        }
        node = b;
        while (first && node) {
            if (first == node) {
                return first;
            }
            first = first->next;
            node = node->next;
        }
        return NULL;
    }
};
```