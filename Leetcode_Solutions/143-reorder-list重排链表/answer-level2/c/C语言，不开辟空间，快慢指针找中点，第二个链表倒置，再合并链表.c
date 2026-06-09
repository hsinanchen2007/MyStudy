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


void mergeList(struct ListNode* cur1, struct ListNode* cur2) {
    struct ListNode *next1, *next2;
    while (cur1 != NULL && cur2 != NULL) {
        next1 = cur1->next;
        next2 = cur2->next;
        cur1->next = cur2;
        cur2->next = next1;
        cur1 = next1;
        cur2 = next2;
    }
    if (cur1 != NULL) {
        cur1->next = cur2;
    }
    return;
}

void reorderList(struct ListNode* head){
    if (head == NULL || head ->next == NULL) {
        return;
    }
    /*快慢指针找中点*/
    struct ListNode *fast, *slow, *mid;
    fast = head;
    slow = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    /*链表一分为二*/
    mid = slow->next;
    slow->next = NULL;
    /*后面的链表倒置*/
    struct ListNode *pre, *cur, *next, *newhead;
    if (mid->next == NULL) {
        newhead = mid;
    } else {
        pre = mid;
        cur = mid;
        next = mid->next;
        mid->next = NULL;
        while (next != NULL) {
            cur = next;
            next = cur->next;
            cur->next = pre;
            pre = cur;
        }
        newhead = cur;
    }
    /*将两个新的链表合并*/
    mergeList(head, newhead);
    return;
}


```