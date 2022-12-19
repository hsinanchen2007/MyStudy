### 解题思路
简单的递归调用。
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
    void TransListNode(ListNode*& head, ListNode*& new_head) {
        if (head != NULL) {
            ListNode* sub_node = head->next;
            sub_node = head->next;
            head->next = new_head;
            new_head = head;
            head = sub_node;
            TransListNode(head, new_head);
        }
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = NULL;
        TransListNode(head, new_head);
        return new_head;
    }
};
```