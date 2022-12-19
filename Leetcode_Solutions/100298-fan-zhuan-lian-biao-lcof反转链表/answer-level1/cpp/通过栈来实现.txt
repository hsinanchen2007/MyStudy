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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> s;
        while(head) {
            s.push(head);
            head = head->next;
        }
        ListNode* res = NULL;
        if (!s.empty()) {
            res = s.top();
            res->next = NULL;
            s.pop();
        }
        else
            return res;
        ListNode* pCur = res;
        while(!s.empty()) {
            pCur->next = s.top();
            s.top()->next = NULL;
            pCur = pCur->next;
            s.pop();
        }
        return res;
    }
};
```