### 解题思路
链表的题都不难，无非就是头插和尾插法的使用。

这里需要注意这个是移动，而不是逆转。

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
    if(!head)
    return head;
    int length=1;
    struct ListNode *r=head,*p=head,*q=head;
    while(q->next)//到末尾节点
    {
        length++;
        q=q->next;
    }
    if(length==1)//长度为1，不能倒置
    return head;
    k%=length;//取余数
    k=length-k;
    while(k>0)
    {
        k--;
        r=p->next;
        p->next=q->next;
        q->next=p;
        q=p;
        p=r;
    }
    return r;
}
```