### 解题思路
此处撰写解题思路

### 代码
正常的链表题目是将上一个节点的next只想下一个节点的val，这样中间那个就会自动消亡，但是这一个题目无法获得上一个节点，那就另辟蹊径将下一个节点的值覆盖此节点，再将此节点的next指向下下个节点的val，这样看起来是删除下一个节点，实质上从用户看来就是删去此节点的值。
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