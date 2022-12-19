```
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode empty(0);
        ListNode* dummy = &empty;
        dummy->next = head;
        ListNode* node = dummy;
        int i = 0;
        while (++i < m) node = node->next;
        ListNode* front = node;
        ListNode* tail = node->next;
        while (++i <= n) {
            auto t = tail->next;
            tail->next = t->next;
            t->next = front->next;
            front->next = t;
        }
        return dummy->next;
    }
};
```
![image.png](https://pic.leetcode-cn.com/1bd28aeeeb8e40249270a9efd32655181f3a9121d14941000559fec97c9023fe-image.png)
