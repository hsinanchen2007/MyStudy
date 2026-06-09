### 解题思路
看代码即懂

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeDuplicateNodes(struct ListNode* head){
    if(!head||!head->next)
    return head;

    int hash[20001]={0};
    //自建头结点
    struct ListNode *new_head=(struct ListNode *)malloc(sizeof(struct ListNode));
    new_head->next=head;

    struct ListNode *p=head,*pre=new_head;
    while(p)
    {
        if(hash[p->val]==0)
        {
            pre->next=p;
            pre=p;
            hash[p->val]=1;
        }
        p=p->next;
    }
    pre->next=NULL;
    return new_head->next;
}
```