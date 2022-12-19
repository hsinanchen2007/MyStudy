### 解题思路
将两个链表节点中的值进行比较，符合条件的加入结果链表，并移动此时被加入结果链表的指针。
最后处理剩下的链表节点;至于为什么是插入而不是直接指向，是因为我不太敢直接操作传入的指针。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//代码未考虑和做过优化。
struct ListNode* createNode(unsigned int val){
    struct ListNode* Node = (struct ListNode *)malloc(sizeof(struct ListNode));
    Node->val = val;
    Node->next = NULL;
    return Node;
}
struct ListNode* insertNode(struct ListNode** list, unsigned int val) {
    struct ListNode** head = list;
    struct ListNode* Node = createNode(val);
    while (*head)head = &(*head)->next;
    (*head) = Node;
    return Node;
}
// #define MIN(A,B)((A) < (B) ? (A) : (B))
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode** l = NULL;
    struct ListNode* result = NULL;
    while (l1 && l2) {
        l = l1->val > l2->val ? &l2 : &l1;
        insertNode(&result, (*l)->val);
        (*l) = (*l)->next;
    }
    //处理剩下的节点
    if (l1)l = &l1;
    if (l2)l = &l2;
    while (l && *l) {
        insertNode(&result, (*l)->val);
        (*l) = (*l)->next;
    }
    return result;
}
```