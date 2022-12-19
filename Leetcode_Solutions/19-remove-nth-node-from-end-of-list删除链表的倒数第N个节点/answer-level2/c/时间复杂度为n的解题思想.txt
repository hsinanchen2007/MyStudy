### 解题思路
使用pre指向链表的第一个节点，p指向第二个，假设链表的长度为len。
当len>n时，使得指针q指向第n+1个节点，此时pre,p,q同时同速度往后面移动，当q指向最后一个节点的时候，p指向倒数第n个节点，pre指向倒数第n+1个节点，删除p即可，    pre->next=p->next；free(p);
若q指向第n个节点时，q->next为空，表示链表长度len==n，此时删除第一个节点即可;

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
    if(n<=0)    return head;
    if(head->next==NULL&&n==1)   return NULL;
    struct ListNode*pre=head;
    struct ListNode *p=head->next;
    struct ListNode*q=head;
    int i;
    for(i=1;i<=n&&q->next!=NULL;i++)
    {
        q=q->next;
    }
    if(i==n)
    {
        head=head->next;
        free(pre);
        return head;
    }
    while(q->next!=NULL)
    {
        pre=p;
        p=p->next;
        q=q->next;
    }
    pre->next=p->next;
    free(p);
    return head;
}
```