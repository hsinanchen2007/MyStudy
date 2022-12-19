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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p,*q;
    int count=0;
    int m=0;
    p=head;
    q=p;
    //只有一个node
    if(head->next==NULL)    return NULL;
    while(q->next!=NULL){
        q=q->next;
        m++;
        if(m>n)    p=p->next; 
    }
    //删除第一个node，将返回第二个node
    if(m<n)    return head->next;
    //printf("%d",n);
    p->next=p->next->next;
    return head;

}
```