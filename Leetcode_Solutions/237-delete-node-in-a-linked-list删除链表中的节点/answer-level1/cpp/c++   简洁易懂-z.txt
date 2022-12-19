### 解题思路
题目描述略微有点含糊，但是思想还是很巧妙的
ps:c++没有垃圾回收，应该删除下一个节点
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
        ListNode* del=node->next;
        node->val=node->next->val;      //使当前节点的val值为下一个节点的val值
        node->next=node->next->next;    //使当前节点指向下下个节点
        delete del;
    }
};
```