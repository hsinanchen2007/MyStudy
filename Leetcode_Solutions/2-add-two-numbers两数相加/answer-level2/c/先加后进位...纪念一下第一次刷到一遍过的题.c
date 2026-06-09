struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
struct ListNode *p1,*p2,*rear,*p3;
p1=l1;p2=l2;
struct ListNode *head=(struct ListNode *)malloc(sizeof(struct ListNode));
head->val=p1->val+p2->val;head->next=NULL;
rear=head;p1=p1->next;p2=p2->next;
while(p1&&p2)
{   
    struct ListNode *p=(struct ListNode *)malloc(sizeof(struct ListNode));
    p->next=NULL;p->val=p1->val+p2->val;
    p1=p1->next;p2=p2->next;
    rear->next=p;rear=p;
}

if(p1==NULL)
{
    while(p2)
    {struct ListNode *p=(struct ListNode *)malloc(sizeof(struct ListNode));
    p->next=NULL;p->val=p2->val;
    rear->next=p;rear=p;
    p2=p2->next;
    }
}
else if (p2==NULL)
{
  while(p1)
    {struct ListNode *p=(struct ListNode *)malloc(sizeof(struct ListNode));
    p->next=NULL;p->val=p1->val;
    rear->next=p;rear=p;
    p1=p1->next;
    }  
}
p3=head;
while(p3->next!=NULL)
{
    if (p3->val>=10)
    {
        p3->val=p3->val%10;
        p3->next->val++;
    } p3=p3->next;
}
if (p3->next==NULL&&p3->val>=10)
{
    struct ListNode *p=(struct ListNode *)malloc(sizeof(struct ListNode));
    p->val=1;p->next=NULL;
    p3->next=p;p3->val%=10;
}
return head;
}
