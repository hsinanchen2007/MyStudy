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
    pair<ListNode*, int> dfs(ListNode* l1, ListNode* l2, int d1, int d2) {
        if (l1 == NULL || l2 == NULL) {
            return {NULL, 0};
        }
        pair<ListNode*, int> p;
        int val = 0;
        if (d1 == d2) {
            p = dfs(l1->next, l2->next, d1 - 1, d2 - 1);
            val = p.second + l1->val + l2->val;
        } else if (d1 > d2) {
            p = dfs(l1->next, l2, d1 - 1, d2);
            val = p.second + l1->val;
        } else {
            p = dfs(l1, l2->next, d1, d2 - 1);
            val = p.second + l2->val;
        }
        auto node = new ListNode(val % 10);
        node->next = p.first;
        return {node, val / 10};
    }
    int depth(ListNode* l) {
        int d = 0;
        while (l != NULL) {
            ++d;
            l = l->next;
        }
        return d;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        int d1 = depth(l1);
        int d2 = depth(l2);
        auto p = dfs(l1, l2, d1, d2);
        if (p.second > 0) {
            auto node = new ListNode(p.second);
            node->next = p.first;
            return node;
        }
        return p.first;
    }
};
```

![image.png](https://pic.leetcode-cn.com/c4fdfd75315957b8d932eecfa1b02144308dbc794ef114e89283fd5b9e6cdbd8-image.png)
