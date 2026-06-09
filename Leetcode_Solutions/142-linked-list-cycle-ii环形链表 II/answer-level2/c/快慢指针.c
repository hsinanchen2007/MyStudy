### 解题思路
先用快慢指针找出相遇的点，然后再令一指针q从相遇点出发，同时p从头节点出发，最终pq相遇的点即是循环开始的节点

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *findcounter(struct ListNode *head){
    struct ListNode *slow = head,*fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            return slow;
    }
    return NULL;
}

struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL)
        return NULL;
    struct ListNode *p = head,*q;
    q = findcounter(head);
    if(q == NULL)
        return NULL;
    while(p != q){
        p = p->next;
        q = q->next;
    }
    return p;
}
```