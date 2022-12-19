# 数组存储+快排+创链赋值
1.创建数组，将链表值全部传入
2.对数组快排
3.创建链表存储数组值
```c
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int s[50000],k=0;
    for(int i=0;i<listsSize;i++)
    {
        while(lists[i]!=NULL)
        {
            s[k++]=lists[i]->val;
            lists[i]=lists[i]->next;
        }
    }
    if(k==0)return NULL;
    qsort(s,k,sizeof(int),cmp);
    struct ListNode *p=NULL,*res,*head;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->val=s[0];
    p=head;
    res=head;
    for(int i=1;i<k;i++)
    {
        head=(struct ListNode*)malloc(sizeof(struct ListNode));
        head->val=s[i];
        p->next=head;
        p=head;
    }
    p->next=NULL;
    return res;
}
```

# Leetcode21合并两个有序链表->合并多个
1.res返回链表置为空
2.将res与lists每行链表合并，更新res
3.返回res
```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head=(struct ListNode *)malloc(sizeof(struct ListNode)),*s=head;
    head->next=NULL;
    while(l1||l2)
    {
        if(l1==NULL)
        {
            head->next=l2;
            break;
        }
        else if(l2==NULL)
        {
            head->next=l1;
            break;
        }
        else if(l1->val<l2->val)
        {
            head->next=l1;
            head=head->next;
            l1=l1->next;
        }
        else
        {
            head->next=l2;
            head=head->next;
            l2=l2->next;
        }
    }
    return s->next;
}

struct ListNode* sortList(struct ListNode* head){
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    struct ListNode *slow=head,*fast=head->next->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    fast=slow->next;
    slow->next=NULL;
    struct ListNode *ans=mergeTwoLists(sortList(head),sortList(fast));
    return ans;
}

```

# Leetcode21合并两个有序链表->148排序链表->合并k个排序链表
1.先创建链表合并
2.链表排序
3.返回链表
```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head=(struct ListNode *)malloc(sizeof(struct ListNode)),*s=head;
    head->next=NULL;
    while(l1||l2)
    {
        if(l1==NULL)
        {
            head->next=l2;
            break;
        }
        else if(l2==NULL)
        {
            head->next=l1;
            break;
        }
        else if(l1->val<l2->val)
        {
            head->next=l1;
            head=head->next;
            l1=l1->next;
        }
        else
        {
            head->next=l2;
            head=head->next;
            l2=l2->next;
        }
    }
    return s->next;
}

struct ListNode* sortList(struct ListNode* head){
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    struct ListNode *slow=head,*fast=head->next->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    fast=slow->next;
    slow->next=NULL;
    struct ListNode *ans=mergeTwoLists(sortList(head),sortList(fast));
    return ans;
}



int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode *q=(struct ListNode *)malloc(sizeof(struct ListNode)),*p=NULL,*res=q;
    for(int i=0;i<listsSize;i++)
    {
        while(lists[i]!=NULL)
        {
            p=(struct ListNode *)malloc(sizeof(struct ListNode));
            p->val=lists[i]->val;
            lists[i]=lists[i]->next;
            q->next=p;
            q=p;
        }
    }
    q->next=NULL;
    res=res->next;
    return sortList(res);
}
```