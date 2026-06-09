执行用时 :
24 ms
, 在所有 c 提交中击败了
86.40%
的用户
内存消耗 :
9.9 MB
, 在所有 c 提交中击败了
90.00%
的用户
```
struct ListNode* sortList(struct ListNode* head)
{
    if(!head||!(head->next)) return head;
    struct ListNode*fast=head->next,*slow=head;
    //search the middle node
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;//寻找链表中点
    }
    struct ListNode*l=head,*r=slow->next;//递归自顶而下，将链表分为左右两个链表来进行归并排序
    slow->next=NULL;
    
    struct ListNode* l1=sortList(l);//l1为左边归并排序好的头结点
    struct ListNode* r1=sortList(r);//l2为右边归并排序好的头结点

    struct ListNode*L, *rear;
    if(l1->val<r1->val)//
    {
        L=l1;
        l1=l1->next;
    }
    else
    {
        L=r1;
        r1=r1->next;
    }
    rear=L;
    rear->next=NULL;
    //以上代码是向新链表L的第一个节点存入左右两个链表的头节点的较小的元素

    while(l1||r1)//注意不是&&
    {
        if(!l1)//当l1已经归并完时，用尾结点指向r1;
        {
        rear->next=r1;
        r1=NULL;
        }
        else if(!r1)//同理
        {
            rear->next=l1;
            l1=NULL;
        }
        else if(l1->val<r1->val)//进行归并
        {
            rear->next=l1;
            l1=l1->next;
            rear=rear->next;
            rear->next=NULL;
        }
        else
        {
            rear->next=r1;
            r1=r1->next;
            rear=rear->next;
            rear->next=NULL;
        }
    }
return L;//返回新链表头结点
}
```
```
    void swap(int *a,int *b){
        int t=*a;
        *a=*b;
        *b=t;
    }
struct ListNode *partion(struct ListNode *pBegin,struct ListNode *pEnd){
        if(pBegin==pEnd||pBegin->next==pEnd)    return pBegin;
        int key=pBegin->val;    //选择pBegin作为基准元素
        struct ListNode *p=pBegin,*q=pBegin;
        while(q!=pEnd){   //从pBegin开始向后进行一次遍历
            if(q->val<key){
                p=p->next;
                swap(&p->val,&q->val);
            }
            q=q->next;
        }
        swap(&p->val,&pBegin->val);
        return p;
    }

void quick_sort(struct ListNode *pBegin,struct ListNode *pEnd){
        if(pBegin==pEnd||pBegin->next==pEnd)    return;
       struct ListNode *mid=partion(pBegin,pEnd);
        quick_sort(pBegin,mid);
        quick_sort(mid->next,pEnd);
    }

struct ListNode* sortList(struct ListNode* head)
{
    if( head == NULL || head->next == NULL )
        return head;
    if(head==NULL||head->next==NULL)    return head;
        quick_sort(head,NULL);
        return head;
}
```
