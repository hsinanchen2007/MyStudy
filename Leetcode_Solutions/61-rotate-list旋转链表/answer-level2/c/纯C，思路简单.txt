### 解题思路
1、将原链表组成一个循环链表
2、原尾指针的移动次数就是num-(k%num);
3、移动，然后将尾指针指向NULL

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
    if(head==NULL||k==0) return head;
    struct ListNode* p=head;
    int num=1;
    while(p->next)
    {
        p=p->next;
        num++;
    }
    p->next=head;
    int movstep=num-(k%num);
    while(movstep>0)
    {
        p=p->next;
        movstep--;
    }
    struct ListNode* res=p->next;
    p->next=NULL;

    return res;
}
```