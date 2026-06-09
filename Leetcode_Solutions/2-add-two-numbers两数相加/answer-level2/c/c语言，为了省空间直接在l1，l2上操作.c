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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int num;
    int x=0;  //记录进位
    struct ListNode *p1=l1; //循环标志
    struct ListNode *p2=l2;
    struct ListNode *l1t=NULL; //尾节点地址记录
    struct ListNode *l2t=NULL;
    while(p1!=NULL && p2!=NULL)
    {
        num=p1->val+p2->val+x;
        x=num/10;
        p1->val=p2->val=num%10;

        l1t=p1;
        l2t=p1;
        p1=p1->next;
        p2=p2->next;
    }
    if(p1==NULL && p2==NULL) //一样长
    {
        if(x==1) //有进位则需要增加节点
        {
            struct ListNode* p=NULL;
            p=(struct ListNode*)malloc(sizeof(struct ListNode));
            p->val=x;
            p->next=NULL;
            l1t->next=p;
        }
        return l1;        
    }
    else if(p2==NULL)  //l1更长,选择l1输出
    {
        while(x==1 && p1!=NULL)
        {
            num=p1->val+x;
            x=num/10;
            p1->val=num%10;

            l1t=p1;
            p1=p1->next;
        }
        if(x==1 && p1==NULL)    //遍历完链表还有进位则需要增加节点
        {
            struct ListNode* p1a=NULL;
            p1a=(struct ListNode*)malloc(sizeof(struct ListNode));
            p1a->val=x;
            p1a->next=NULL;
            l1t->next=p1a;
        } 
        return l1;
    }
    else if(p1==NULL)  //l2更长
    {
        while(x==1 && p2!=NULL)
        {
            num=p2->val+x;
            x=num/10;
            p2->val=num%10;

            l2t=p2;
            p2=p2->next;
        }
        if(x==1 && p2==NULL)    //遍历完链表还有进位则需要增加节点
        {
            struct ListNode* p2a=NULL;
            p2a=(struct ListNode*)malloc(sizeof(struct ListNode));
            p2a->val=x;
            p2a->next=NULL;
            l2t->next=p2a;
        } 
        return l2;
    }
    return l1;
}
```