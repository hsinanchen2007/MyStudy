### 解题思路
代码非常清晰，不明白的欢迎提问`

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    if(!head||!head->next)
    return head;

    //自建头结点
    struct ListNode* new_head=(struct ListNode*)malloc(sizeof(struct ListNode));
    new_head->next=head;

    struct ListNode* pre,*q,*r;
    pre=head;
    while(pre->next)
    {
        q=pre->next;
        if(q->val<pre->val)//发生逆序
        {
            r=q->next;//分离q
            pre->next=r;
            struct ListNode *p=new_head;
            while(p->next->val<q->val)
            p=p->next;
            q->next=p->next;
            p->next=q;
        }
        else//容易忽略
        pre=pre->next;
    }
    return new_head->next;
}
```
把链表存储在数组中进行排序
```c
int getlength(struct ListNode *head)
{
    int length=0;
    while(head)
    {
        head=head->next;
        length++;
    }
    return length;
}
struct ListNode* insertionSortList(struct ListNode* head){//数组里面到底存的是什么
    if(!head||!head->next)
    return head;
    int length=getlength(head);
    struct ListNode *num[length];

    int i,j;
    i=0;
    while(head)//存起来
    {
        num[i++]=head;
        head=head->next;
    }
    for(i=1;i<length;i++)
        if(num[i]->val<num[i-1]->val)//发生逆序
        {//二分查找
            int low=0;
            int high=i-1;
            int mid;
            while(high>=low)
            {
                mid=low+(high-low)/2;
                if(num[mid]->val>num[i]->val)high=mid-1;
                else
                low=mid+1;
            }
            struct ListNode *temp=num[i];
            for(j=i-1;j>=high+1;j--)//后移
            num[j+1]=num[j];
            num[high+1]=temp;
        }
    for(i=0;i<length-1;i++)
    num[i]->next=num[i+1];
    num[i]->next=NULL;
    return num[0];

}
```
