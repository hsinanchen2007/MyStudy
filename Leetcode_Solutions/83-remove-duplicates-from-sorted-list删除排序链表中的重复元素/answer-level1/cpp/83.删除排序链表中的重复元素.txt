### 解题思路
常规的遍历链表的方法，需要考虑传入的链表为空的特殊情况

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* cur = head;
        while (cur->next != NULL) 
        {
            ListNode* ptr = cur;
            while (ptr->next != NULL)
            {
                if (ptr->next->val == cur->val) {
                    ListNode* tmp = ptr->next;
                    ptr->next = ptr->next->next;
                    tmp->next = NULL;
                    delete tmp;
                }
                else
                    ptr = ptr->next;
            }
            if (cur->next != NULL)
                cur = cur->next;
        }
        return head;
    }
};
```