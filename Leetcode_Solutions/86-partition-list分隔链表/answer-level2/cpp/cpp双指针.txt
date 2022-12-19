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
    ListNode* partition(ListNode* head, int x) {
        auto h = new ListNode(0);
        h->next = head;
        auto l = h;
        while (l->next && l->next->val < x) l = l->next;
        auto p1 = l->next;
        auto p2 = l;
        while (p1) {
            if (p1->val < x) {
                auto t1 = p1->next;
                auto t2 = l->next;
                l->next = p1;
                p1->next = t2;
                p2->next = t1;
                l = l->next;
                p1 = t1;
            } else {
                p1 = p1->next;
                p2 = p2->next;   
            }
        }
        return h->next;
    }
};
```