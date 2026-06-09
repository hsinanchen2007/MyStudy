### 解题思路
刚开始没有看懂题目，我以为是写一个函数删除给定值的节点。while node到null。然而发现错了。
看了看题解，然来是没有弄懂题目。
这题没有任何营养。

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
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```