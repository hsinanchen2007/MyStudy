### 解题思路
依次将要删除节点后面节点的值复制给前一个节点即可，唯一需要注意的是，如果node->next->next为空，说明到了倒数第二个节点，此时应该将node->next置空，否则最后一个节点会重复。

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
            while(node->next->next)
            {
            node->val=node->next->val;
            node=node->next;
            }
                node->val=node->next->val;
                delete node->next;
                node->next=NULL;
    }
};
```