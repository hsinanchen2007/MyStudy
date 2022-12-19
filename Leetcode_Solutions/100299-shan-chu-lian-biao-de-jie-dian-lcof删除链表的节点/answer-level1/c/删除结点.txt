### 解题思路
题目不难，定义一个指向被删结点前驱的指针即可

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    if(head->val==val) return head->next;
    struct ListNode *p,*q;
    p=head;q=p->next;
    while(q){
        if(q->val==val){
            p->next=q->next;
            return head;
        }
        p=p->next;
        q=q->next;
    }
    return head;
}


```