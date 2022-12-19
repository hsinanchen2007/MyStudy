### 解题思路
找出偶数结点，然后依次插入末尾即可
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(head==NULL || head->next==NULL || head->next->next==NULL)
        return head;
    struct ListNode *p=head,*q=head->next,*tail=head;
    int len=1;
    while(tail->next!=NULL)
    {
        tail=tail->next;
        len++;
    }
    for(int count=2;count<=len;count++)
    {
        if(count%2==0)
        {
            p->next=q->next;
            tail->next=q;
            q->next=NULL;
            tail=q;
            q=p->next;
        }
        else
        {
            q=q->next;
            p=p->next;
        }
    }
    return head;
}
```