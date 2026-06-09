### 解题思路
此处撰写解题思路

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
    struct ListNode *node1 = l1;
    struct ListNode *node2 = l2;
    struct ListNode *curnode = NULL;
    struct ListNode *head = NULL;

    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    if (node1->val < node2->val) {
        curnode = node1;
        node1 = node1->next;
    }
    else {
        curnode = node2;
        node2 = node2->next;
    }
    head = curnode;

    while (1) {
        if (node1 == NULL) {
            curnode->next = node2;
            break;
        }
        if (node2 == NULL) {
            curnode->next = node1;
            break;
        }

        if (node1->val < node2->val) {
            curnode->next = node1;
            node1 = node1->next;
        } else {
            curnode->next = node2;
            node2 = node2->next;
        }
        curnode = curnode->next;
    }

    return head;
}
```