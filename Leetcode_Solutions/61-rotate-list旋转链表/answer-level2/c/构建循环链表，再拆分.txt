### 解题思路
遇到循环的问题，记得要取余

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){


    if(head == NULL || k == 0) return head;

    struct ListNode *p = head;
    int L = 0;
    while(p->next){
        p = p->next;
        L++;
    }
    p->next = head;
    
    L++;
    int num = L - (k % L) - 1;
    
    p = head;
    while(num){
        num--;
        p = p->next;
    }
    head = p->next;
    p->next = NULL;
    return head;
}
```