### 解题思路
用递归写的，你也可以用栈，或者直接每次插入到头部。

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
    void do_reversePrint(vector<int> &res, ListNode *head) {
        if (head->next == NULL) {
            res.emplace_back(head->val);
        } else {
            do_reversePrint(res, head->next);
            res.emplace_back(head->val);
        }
    }

    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if (head == NULL) {
            return res;
        }
        do_reversePrint(res, head);
        return res;
    }
};
```