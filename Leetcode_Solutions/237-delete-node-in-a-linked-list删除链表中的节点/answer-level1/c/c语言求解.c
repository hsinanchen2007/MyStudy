### 解题思路
首先该题传入的参数是一个将要被删除的节点的地址，并不是头结点。
其次，因为函数的形参为一级指针，所以想要free掉该节点是不可能的，
所以，只能释放后面的一个节，并将后面结点的值及后面节点的指向地址赋给node结点

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
    struct ListNode *p = node->next;
    node->val = p ->val;
    node->next = node->next->next;
    free(p);
}
```