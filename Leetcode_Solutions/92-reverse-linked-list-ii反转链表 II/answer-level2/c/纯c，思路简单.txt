### 解题思路
利用头插法和尾插法
1、当计数值 m<=count<=n 时，执行头插法，倒序
2、当计数值 m > count 时，执行尾插法，正序

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode* newhead=(struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next=NULL;
    struct ListNode* h=newhead;//头指针
    struct ListNode* r=newhead;//尾指针
    struct ListNode* p=head;//遍历指针
    int count=1;

    while(p)
    {
        if(count<m)//尾插法
        {
            r->next=p;
            p=p->next;
            r=r->next;
            r->next=NULL;

            h=h->next;
        }
        else if(m<=count&&count<=n)//头插法
        {
            struct ListNode* tmp=p;
            p=p->next;
            tmp->next=h->next;
            h->next=tmp;
            if(count==m)
                r=r->next;
        }
        else
        {
            r->next=p;
            break;
        }
        ++count;
    }

    return newhead->next;
}
```