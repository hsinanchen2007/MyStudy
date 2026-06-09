### 解题思路
这种题目一般都是要有一个dummy head比较容易操作.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* pHead = new ListNode(5);
        auto p = pHead;
        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
            else
            {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
        }

        if (l1) p->next = l1;
        if (l2) p->next = l2;

        return pHead->next;
    }
};
```