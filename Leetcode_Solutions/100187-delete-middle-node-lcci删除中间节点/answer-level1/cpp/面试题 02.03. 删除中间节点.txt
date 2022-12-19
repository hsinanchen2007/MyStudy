### 解题思路
时空复杂度100%，思路是李代桃僵，因为不会是最后一个节点，不会触发错误。我个人认为删不删除节点都可以。直接看代码很好懂

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
        node->val=node->next->val;
        node->next=node->next->next;
        
    }
};
```