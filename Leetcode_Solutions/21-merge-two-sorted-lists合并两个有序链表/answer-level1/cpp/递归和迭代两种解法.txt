### 解题思路
基本上就是归并排序的思路

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *rear = dummy;

        while (l1 != nullptr && l2 != nullptr) {
            int minVal;
            if (l1->val <= l2->val) {
                minVal = l1->val;
                l1 = l1->next;
            } else {
                minVal = l2->val;
                l2 = l2->next;
            }

            ListNode *newNode = new ListNode(minVal);
            rear->next = newNode;
            rear = newNode;
        }

        if (l1 != nullptr) {
            rear->next = l1;
        } else {
            rear->next = l2;
        }

        return dummy->next;
    }
};

#if 0
// DFS
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
#endif
```