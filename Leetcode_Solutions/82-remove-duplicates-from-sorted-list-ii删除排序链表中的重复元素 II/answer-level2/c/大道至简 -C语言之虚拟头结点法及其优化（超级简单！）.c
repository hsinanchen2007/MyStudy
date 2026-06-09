# 做题思路：

1. 问题核心，找到不重复的结点，此时需判断多次，不能只认为当前面元素不等于后面元素时，此时这个后面的元素就是不重复的结点，如{1,1,1,2,2}这时不能认为2为不重复的结点，可以使用跳蛙思想来搞定：当元素相等时，head指针不动，p指针向后遍历，当不满足相等的条件时，将p指针的位置赋值给head，p=p->next；继续判断是否相等，直至找到不重复的结点。
2. 插入head这个不重复的结点，要注意的是head->next为NULL时，跳出循环
3. 当while大循环结束后，若head这个不重复的结点有值继续插入
```
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *p,*L,*q;

    if(!head||!(head->next))  return head;
    L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=NULL;//新建一个链表头结点指向原链表head,
    p=L;
    q=head->next;

while(q)
{
    if(q->val==head->val)//判断是否相等
    {
        
        while(q->val==head->val)
        {
            q=q->next;//若结点数据域相等，继续遍历
            if(!q)//判断是否到链表的末尾
            break;//跳出循环
        }
        if(q!=NULL)//不为表尾，将q的位置赋给head，q继续遍历
       {
        head=q;
        q=q->next;
       }
       else//为表尾，说明元素全都是重复的结点，令其为NULL，跳出循环
       {
        head=q=NULL;
       }    
    }
    else//找到不为重复元素的结点
    {
        p->next=head;//指向这个结点
        p=p->next;//前移
        head=head->next;//前移
        if(!head)
         break;
        q=q->next;//前移

    }

}
if(head)//特殊情况时，当head有值，p为null时
    p->next=head;
else
   p->next=NULL;
    return L->next;
}
```
**//优化后的代码**
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){

    if(!head||!(head->next))  return head;//特殊情况

    struct ListNode * preHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * curNode = NULL;
    struct ListNode * slowP   = NULL;
    struct ListNode * quickP  = NULL;
    int n = 0;
    preHead->next = head;//构造虚拟头结点
    curNode = preHead;
    slowP = head;
    while(slowP)
    {
        for(n=0,quickP=slowP->next;quickP!=NULL;n++,quickP=quickP->next)//开始判断是否循环，slowp指针保持不动
        {
            if(slowP->val!=quickP->val)
              break;
        }
        if(n==0)//进行0次循环，故两值不相等，故为不重复的结点，对重复结点进行删除
        {
            curNode->next=slowP;
            curNode=curNode->next;
        }
        else if(!quickP)//特殊情况
        {
            curNode->next=NULL;尾指针指向null
            break;
        }
        slowP=quickP;//迭代进行循环，n>0时
    } 
    return preHead->next;
}
```


