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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || !head->next) return head;

        int n = 0;
        auto p = head;
        while (p) {
            n++;
            p = p->next;
        }

        int groups = n / k;

        stack<ListNode*> stack; p = head;
        auto dummy = new ListNode(0), tail = dummy;
        for (int i = 0; i < groups; i++) {
            for (int j = 0; j < k; j++) {
                stack.push(p);
                p = p->next;
            }
            while (!stack.empty()) {
                tail = tail->next = stack.top();
                stack.pop();
            }
        }

        tail->next = p;
        return dummy->next;
    }
};
```