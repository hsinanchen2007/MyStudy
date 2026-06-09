### 解题思路
此处撰写解题思路

（1）链表首先走k步；
（2）p1指向头结点，p2指向走k步后的结点，然后同时向前走，当p2走到末尾的时候，p1指向的结点就是要求的结点；

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int kthToLast(struct ListNode* head, int k){
    int i, j;
    struct ListNode *temp1, *temp2;

    temp1 = head;
    temp2 = head;

    for (i = 0; i < k; i++) {
        temp1 = temp1->next;    
    }

    while (temp1 != NULL) {
        temp1 = temp1-> next;
        temp2 = temp2->next;
    }

    return temp2->val;
}

```