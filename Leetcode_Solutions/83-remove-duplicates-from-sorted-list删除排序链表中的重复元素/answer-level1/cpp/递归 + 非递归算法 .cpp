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
    ListNode* deleteDuplicates2(ListNode* head) { // 递归算法

        if (!head || !head->next) return head;

        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }

    ListNode* deleteDuplicates(ListNode* head) { // 非递归算法

        if (!head || !head->next) return head;

        ListNode* p = head;
        while (p && p->next) {
            if (p->val == p->next->val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }

        return head;
    }
};
```