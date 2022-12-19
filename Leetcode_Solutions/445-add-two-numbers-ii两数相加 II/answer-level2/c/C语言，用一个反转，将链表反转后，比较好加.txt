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
 typedef struct ListNode Linklist;
Linklist *reverselist(Linklist*head)
{
    Linklist*tmp1,*tmp2,*tmp3;
    tmp1=head;
    tmp2=head->next;
    
    if(head==NULL)
    {
        printf("空链表！");
        return NULL;
    }
    if(tmp2==NULL)          //只有一个节点
        return tmp1;
    tmp3=head->next->next;
    while(tmp3!=NULL)
    {
        tmp2->next=tmp1;
        tmp1=tmp2;
        tmp2=tmp3;
        tmp3=tmp3->next;
    }
    tmp2->next=tmp1;      //将末尾节点转置
    head->next=NULL;      //将头结点下一个置空
    return tmp2;
    
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1->val==0)
        return l2;
    if(l2->val==0)
        return l1;
    if(l1->next==NULL&&l2->next==NULL)
    {
        int me=l1->val+l2->val;
        if(me<10)
        {
            Linklist*newnode=(Linklist*)malloc(sizeof(Linklist));
            newnode->val=me;
            newnode->next=NULL;
            return newnode;
        }
        else if(me>=10)
        {
            int me1=me%10;
            me=(me-me1)/10;
            Linklist*newnode=(Linklist*)malloc(sizeof(Linklist));
            newnode->val=me1;
            newnode->next=NULL;
            Linklist*newnode1=(Linklist*)malloc(sizeof(Linklist));
            newnode1->val=me;
            newnode1->next=newnode;
            return newnode1;
        }
        

    }
    l1=reverselist(l1);
    l2=reverselist(l2);
    int tmp=0;
    int tmp1=l2->val+l1->val;
    l1=l1->next;
    l2=l2->next;
    if(tmp1>=10)
    {
        tmp1=tmp1%10;
        tmp=1;
    }
    Linklist*nownode=(Linklist*)malloc(sizeof(Linklist));
    nownode->val=tmp1;
    nownode->next=NULL;
    do{
        if(l1!=NULL&&l2!=NULL)
        {
        int tmp4=l2->val+l1->val+tmp;
        tmp=0;
        if(tmp4>=10)
        {
            tmp4=tmp4%10;
            tmp++;
        }
        Linklist*newnode=(Linklist*)malloc(sizeof(Linklist));
        newnode->val=tmp4;
        newnode->next=nownode;
        nownode=newnode;
        l1=l1->next;
        l2=l2->next;
        }
        else if(l1==NULL&&l2!=NULL)
        {
            Linklist*newnode=(Linklist*)malloc(sizeof(Linklist));
            int tmp5=l2->val+tmp;
            tmp=0;
            if(tmp5>=10)
            {
                tmp5=tmp5%10;
                tmp++;
            }
            newnode->val=tmp5;
            newnode->next=nownode;
            nownode=newnode;
            l2=l2->next;
        }
        else if(l2==NULL&&l1!=NULL)
        {
            Linklist*newnode=(Linklist*)malloc(sizeof(Linklist));
            int tmp6=l1->val+tmp;
            tmp=0;
            if(tmp6>=10)
            {
                tmp6=tmp6%10;
                tmp++;
            }
            newnode->val=tmp6;
            newnode->next=nownode;
            nownode=newnode;
            l1=l1->next;

        }
    }while(l1!=NULL||l2!=NULL);
    if(tmp>0)
    {

    
    Linklist*newnode=(Linklist*)malloc(sizeof(Linklist));
    newnode->val=tmp;
    newnode->next=nownode;
    nownode=newnode;
    }
    return nownode;
    
}
```