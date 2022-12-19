### 解题思路
该题思路较为简单，由于该函数仅能访问需删除的节点，解题思路如下：
* 创建临时节点，保存node的下一个节点
* 将node节点的值替换为下一个节点的值
* 将node->next指针指向node->next->next

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) 
{
    struct ListNode *tmp;
    tmp = node->next;
    node->val = tmp->val;
    node->next = tmp->next; 
}
```