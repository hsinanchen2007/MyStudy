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
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next || k == 0)
            return head;

        int n = 1;
        ListNode *tail = head;
        while (tail->next) {
            n++;
            tail = tail->next;
        }

        k %= n;
        if (k == 0) return head;

        ListNode* p = head;
        for (int i = 0; i < n - k - 1; i++)
            p = p->next;

        ListNode* newHead = p->next;
        p->next = nullptr;
        tail->next = head;

        return newHead;
    }
};
```