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
    void deleteNode(ListNode* node) {
        auto t = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete t;
        t = NULL;
    }
};
```

![image.png](https://pic.leetcode-cn.com/6d08a6334b631813f97e6fbe473a34c80a3b9ce6c07caf81c655fd3e6d0b3cb3-image.png)
