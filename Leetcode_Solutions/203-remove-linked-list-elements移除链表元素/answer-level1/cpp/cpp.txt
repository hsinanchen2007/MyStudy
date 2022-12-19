### 解题思路

简单题，使用一个dummy node好写点
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return (ListNode*)nullptr;
        ListNode prenode(0), *root = &prenode;
        while (head) {
            while (head && head->val == val) head = head->next;
            root->next = head;
            root = root->next;
            if (head)
                head = head->next;
        }
        return prenode.next;
    }
};
```