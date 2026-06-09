### 解题思路
先遍历，把一开始的几个满足条件的节点去掉。

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
        if(head == NULL)
            return NULL;
        while(head->val == val && head->next != NULL)
        {
            head = head->next;
        }
        if(head->next == NULL && head->val == val)
            return NULL;
        ListNode * pre, *p;
        pre = head;
        p = head;
        p = p->next;
        while(p != NULL)
        {
            if(p->val == val)
            {
                pre->next = p->next;
                p = p->next;
            }
            else
            {
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};
```