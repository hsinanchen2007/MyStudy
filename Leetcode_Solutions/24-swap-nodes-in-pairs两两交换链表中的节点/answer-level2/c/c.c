### 解题思路
为了将第一个节点的处理一般化，设置一个头节点，然后两两交换即可，要注意循环结束的条件。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *p,*q,*r;
    struct ListNode *new_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(head == NULL || head->next == NULL) return head;

    new_head->next = head;
    r = new_head;

    p = head;
    q = head->next;
    

    while(p && q){
        r->next = q;
        p->next = q->next;
        q->next = p;
        p = p->next;
        if(p == NULL) break;
        else{
            if(p->next == NULL) break;
            else{
                r = q->next;
                q = p->next;
            }
        }
    }

    return new_head->next;



}
```