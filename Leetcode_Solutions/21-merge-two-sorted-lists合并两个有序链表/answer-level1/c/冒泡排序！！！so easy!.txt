```
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL)
      return l2;
    if(l2==NULL)
      return l1;//l1不为空且l2为空
struct ListNode* p=l1;
struct ListNode* q;

//将两个链表首位相接直接构成一个链表
while(p->next!=NULL)
    p=p->next;

p->next=l2;
//冒泡排序排列val值
int temp;
for(p=l1;p;p=p->next)
{
    struct ListNode *ptr;  
    for(q=p->next;q;q=q->next)
    {
        ptr=p;
        if(ptr->val>q->val)
        {
            temp=q->val;
            q->val=p->val;
            p->val=temp;
        }
        else
        {
            ptr=q;

        }
    }
}
return l1;
}
```
