### 解题思路
很简单的思路，生成一个新链表存储和的值，各个位数相加，超过10进位，注意两个链表的长度的不同就行。最小的链到末尾之后，如果没有进位直接将长链后面的节点接到新链表之后就行，不用再生成链表。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

        struct ListNode *l3=(struct ListNode*)malloc(sizeof(struct ListNode));
        l3->next=NULL;
        struct ListNode *p,*p1,*p2;
        p=l3;
        p1=l1;
        p2=l2;
        int nextadd=0;
        while(p1!=NULL && p2!=NULL)
        {
            int num = p1->val+p2->val;
            if(nextadd==1)
            {
                num=num+1;
                nextadd=nextadd-1;
            }
            if(num>=10){
                num=num-10;
                nextadd=nextadd+1;
            }
            p->val = num;
            if(p1->next==NULL && p2->next==NULL)
            {
                if(nextadd==1)
                {
                    p=p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
                    p->val=nextadd;
                }
                p->next=NULL;
                p1=p1->next;
                p2=p2->next;
            }
            else
            {
                p=p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
                p->next=NULL;
                p1=p1->next;
                p2=p2->next;
            }
        }
        if(p2!=NULL)
        {
            if(nextadd==1)
            {
                while(p2!=NULL&&p2->val==9)
                {
                    p->val=0;
                    nextadd=1;
                    p2=p2->next;
                    if(p2==NULL)
                    {
                        p=p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
                        p->next=NULL;
                        p->val=1;
                    }
                    else
                    {
                        p=p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
                        p->next=NULL;
                    }
                }
                if(p2!=NULL) 
                {
                    p->val=p2->val+nextadd;
                    p->next=p2->next;
                }
            }
            else
            {
                p->val=p2->val;
                p->next=p2->next;
            }
        }
        else if(p1!=NULL)
        {
           if(nextadd==1)
            {
                while(p1!=NULL&&p1->val==9)
                {
                    p->val=0;
                    nextadd=1;
                    p1=p1->next;
                    if(p1==NULL)
                    {
                        p=p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
                        p->next=NULL;
                        p->val=1;
                    }
                    else
                    {
                        p=p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
                        p->next=NULL;
                    }
                }
                if(p1!=NULL) 
                {
                    p->val=p1->val+nextadd;
                    p->next=p1->next;
                }
            }
            else
            {
                p->val=p1->val;
                p->next=p1->next;
            }
        }
        
    return l3;
}
```