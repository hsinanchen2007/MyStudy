### 解题思路
递归   （关注微信公众号'码农黑板报'获取更多题解）

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
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        recursive(res, head);
        return res;
    }

    void recursive(vector<int>& res, ListNode* node) {
        if (node == NULL) {
            return;
        }
        recursive(res, node->next);
        res.push_back(node->val);
    }
};
```