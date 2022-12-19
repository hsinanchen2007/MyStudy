### 解题思路
由于是单链表，因此，没办法对当前节点的前序节点操作。因此，只能考虑操作当前节点的后续节点：
1.将当前节点的下一个节点的值赋值给当前节点。
2.把当前节点的next指针指到下下一个节点。
3.删除当前节点的下一个节点。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
	
	struct ListNode *del = NULL;
	del = node->next;
	node->val = node->next->val;
	node ->next = node->next->next;
	free(del);
	return;
    
}
```