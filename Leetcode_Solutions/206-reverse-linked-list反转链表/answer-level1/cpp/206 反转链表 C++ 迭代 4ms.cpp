### 解题思路
![image.png](https://pic.leetcode-cn.com/5a2427b26536f50970f32b70bfbabd197c6cec6ed304fb5e90c5c4ea5ded573f-image.png)
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
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        stack<ListNode*> s;
        while (head) {
            s.push(head);
            head = head -> next;
        }
        head = s.top();
        s.pop();
        head->next = NULL;
        ListNode* cur = head;
        while (!s.empty()) {
            cur->next = s.top();
            s.pop();
            cur = cur->next;
            cur->next = NULL;
        }
        return head;
    }
};
```