### 解题思路
此处撰写解题思路
写一个反转函数即可
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
    void Swap(ListNode *&a, ListNode *&b) {
        swap(a, b->next);
        swap(a, b);
    }
    using P = pair<ListNode*,ListNode*>;
    ListNode *reve(ListNode *top, ListNode *tail) {
        ListNode *cnt = NULL, *ta = top;
        for (;top != tail;) {
            Swap(cnt, top);
        }
        ta->next = tail;
        return cnt;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (n == m) return head;
        ListNode *top = NULL, *tail = head;
        for (int i = 1; i <= n; ++i) {
            if (i+1 == m) top = tail;
            tail = tail->next;
        }
        if (m == 1)
            head = reve(head, tail);
        else top->next = reve(top->next, tail);
        return head;
    }
};
```