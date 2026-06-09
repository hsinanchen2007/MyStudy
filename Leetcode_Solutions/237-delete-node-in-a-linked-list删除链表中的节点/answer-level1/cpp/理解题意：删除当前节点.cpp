### 解题思路
主要是要理解题意，题目给定的是要删除的那个节点，只需要将下一个节点的值复制过来再连上下下一个节点就好。

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
        node->next =  node->next->next;
    }
};
```