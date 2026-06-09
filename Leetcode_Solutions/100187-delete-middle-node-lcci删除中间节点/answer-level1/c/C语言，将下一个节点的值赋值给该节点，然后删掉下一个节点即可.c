
``` c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* q = NULL;
    // 将下一个节点赋值给该节点
    node->val = node->next->val;
    q = node->next;
    // 删掉给出节点的下一个节点
    node->next = q->next;
	// 释放掉
    free(q);
}
```

