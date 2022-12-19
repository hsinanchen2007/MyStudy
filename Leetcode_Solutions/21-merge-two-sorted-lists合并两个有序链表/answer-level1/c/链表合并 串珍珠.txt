### 解题思路
此处撰写解题思路
复用l1和l2的节点，将其像珍珠一样串起来
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    int l1Idx;
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    } else if (l1 == NULL) {
        return l2;
    }  else if (l2 == NULL) {
        return l1;
    }

    struct ListNode *l1NextNode = l1;
    struct ListNode *l2NextNode = l2;
    struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *curListNode = ret;

    while (l1NextNode != NULL && l2NextNode != NULL) {
        if (l1NextNode->val <= l2NextNode->val) {
            curListNode->next = l1NextNode;
            l1NextNode = l1NextNode->next;

        } else {
            curListNode->next = l2NextNode;
            l2NextNode = l2NextNode->next;

        }

        curListNode = curListNode->next;
    }

    if (l1NextNode != NULL && l2NextNode == NULL) {
        curListNode->next = l1NextNode;
    } else if (l2NextNode != NULL && l1NextNode == NULL) {
        curListNode->next = l2NextNode;
    } else {
        curListNode->next = NULL;
    }

    return ret->next;

}
```