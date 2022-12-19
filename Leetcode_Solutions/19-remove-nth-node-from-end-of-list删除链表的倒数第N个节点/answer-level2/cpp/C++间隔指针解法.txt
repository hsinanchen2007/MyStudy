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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (NULL == head)
            return head;
        ListNode* original = head;
        ListNode* node = original;

        int i = 0;
        while (head != NULL && i <= n)
        {
            i++;
            head = head->next;
        }
        while (head != NULL)
        {
            head = head->next;
            original = original->next;
        }

        if (original->next == NULL)
            return NULL;

        if (original->next != NULL && i <= n)
        {
            original = original->next;
            return original;
        }
        else
            original->next = original->next->next;

        return node;
    }
};
```