### 解题思路
看题目描述就是比较简单的题目。就是按位进行累加，主要注意进位问题。

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = new ListNode(0);
        add(p, l1, l2, 0);
        return p->next;
    }

    void add(ListNode* p, ListNode* l1, ListNode* l2, int carry)
    {
        if (l1 != NULL || l2 != NULL)
        {
            int count = carry;
            if (l1 != NULL) count += l1->val;
            if (l2 != NULL) count += l2->val;
            ListNode* n = new ListNode(count % 10);
            p->next = n;
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
            add(p->next, l1, l2, count / 10);
        }
        else
        {
            if (carry == 1)
            {
                ListNode* n = new ListNode(1);
                p->next = n;
            }
        }
    }
};
```