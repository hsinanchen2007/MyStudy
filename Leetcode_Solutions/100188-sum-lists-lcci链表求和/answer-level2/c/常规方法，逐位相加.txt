### 解题思路


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
    int c=0,sum=0;
    struct ListNode *l3=(struct ListNode*)malloc(sizeof(struct ListNode));
    l3->next=NULL;
    struct ListNode *p1,*p2,*r;
    p1=l1;p2=l2,r=l3;
    while(p1||p2){
        int s1=p1?p1->val:0;    //当p1或p2为空时，值取0
        int s2=p2?p2->val:0;
        sum=s1+s2+c;
        struct ListNode *p3=(struct ListNode*)malloc(sizeof(struct ListNode));
        if(sum>=10){
            p3->val=sum%10;
            c=1;
        }
        else{
            p3->val=sum;
            c=0;
        }
        p3->next=r->next;
        r->next=p3;
        r=p3;       //后插法，让r一直指向尾结点
        if(p1!=NULL)p1=p1->next;
        if(p2!=NULL)p2=p2->next;
    }
    if(c!=0){       //最后还要再判断一次进位
        struct ListNode *a=(struct ListNode*)malloc(sizeof(struct ListNode));
        a->val=c;
        a->next=r->next;
        r->next=a;
    }
    return l3->next;
}
```