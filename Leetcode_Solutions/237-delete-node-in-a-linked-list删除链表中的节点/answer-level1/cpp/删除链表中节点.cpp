### 解题思路
此处撰写解题思路
这题本意是删除当前node节点。一般情况下，需要知道node节点的前驱和后继。本题中无此参数，可以将node节点的后继覆盖node，然后删除后继节点。很是精妙！
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
    void deleteNode(ListNode* node) {
            ListNode *del = node->next;
            node->val = node->next->val;node->next = node->next->next;
            delete del;
    }
};
```