```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode*p;
    p=node->next;
    node->val = p->val;
    node->next = p->next;
    free(p);
}
//别忘记释放内存哦

```
