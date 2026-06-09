### 解题思路
注意有链表为空的情况，注意两个链表都只有一级的情况，循环前面三个if就是为了排除这两种情况的
循环中如果发现有一个链表后面没东西了，记得把current指向另一个链表，然后就可以安心结束循环了
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
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    struct ListNode * head = l1->val <= l2->val ? l1 : l2;
    struct ListNode * current = head;
    struct ListNode * nextNode = l1->val > l2->val ? l1 : l2;
    struct ListNode * temp = current->next;
    if (temp == NULL) {
        current->next = nextNode;
        return head;
    }
    while (nextNode != NULL && temp != NULL) {
        if (nextNode->val <= temp->val) {
            current->next = nextNode;
            current = nextNode;
            nextNode = current->next;
        } else {
            current->next = temp;
            current = temp;
            temp = current->next;
        }
        if (nextNode == NULL) {
            current->next = temp;
        }
        if (temp == NULL) {
            current->next = nextNode;
        }
    }
    return head;
}
```