### 解题思路
这道题没有给整个链表。就给了节点。
目的就是删除这个节点本身，但是删除节点必须要知道前一个节点。所以转化为删除下一个节点。
那么就是把下一个节点的值复制过来。再把下一个节点删掉。

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