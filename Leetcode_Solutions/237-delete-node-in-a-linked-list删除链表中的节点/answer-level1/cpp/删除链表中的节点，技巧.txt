### 解题思路
题目要求删除一个节点。
那么删除有两种方式，一种是传统的，需要用到删除节点的前驱。
还有一种采用值的覆盖，一个小技巧。，很灵活
吐槽一下，题目居然直接给出删除节点的指针

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
       // 题目要求删除节点node,但因为没有前驱。

       node->val = node->next->val;
       ListNode *temp=node->next;
       node->next=node->next->next;
       delete temp;
    }
};
```