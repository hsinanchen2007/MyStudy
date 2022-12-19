### 解题思路
设置快慢指针p,q初始同时指向head
先让快指针q先next  k次
在同时让p，q进行next，直到q为空
返回p->val
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
    struct ListNode*p,*q;
    p=head;
    q=head;

    for(int i=0;i<k;i++)
        q=q->next;
    while(q!=NULL)
    {
        p=p->next;
        q=q->next;
    }

    return p->val;
}
```