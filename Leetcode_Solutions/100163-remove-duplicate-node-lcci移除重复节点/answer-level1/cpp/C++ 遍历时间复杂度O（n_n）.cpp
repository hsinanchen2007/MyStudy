### 解题思路
两次遍历，遍历当前节点的时候，对当前节点后面的所有同值节点要删除。

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
    ListNode* removeDuplicateNodes(ListNode* head) {
        #if 0
        ListNode* cur = head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = cur;

        while(cur != NULL && cur->next != NULL)
        {
            if(cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy->next;
        #else

        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* cur = head;
        ListNode* next = NULL;
        ListNode* tmp = NULL;
        while(cur != NULL)
        {
            tmp = cur;
            next = cur->next;
            while(next != NULL)//对当前节点后面的所有节点遍历一遍
            {
                if(cur->val == next->val)
                {
                    tmp->next = next->next;
                }
                else
                {
                    tmp = next;
                }
                next = tmp->next;
            }
            cur = cur->next;
        }
        return head;
        #endif
    }
};
```