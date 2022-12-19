### 解题思路
第一个思路是将两个链表分别转换成数字然后相加得到结果，再将结果按照逆序转换成链表输出。提交失败。
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    long long l1ToInt=0;
    long long l2ToInt=0;
    long long sum=0;
    int i=1;
    struct ListNode *pNewList=(struct ListNode*)malloc(sizeof(struct ListNode));
    pNewList->val=-1;
    pNewList->next=NULL;
    struct ListNode *pTemp=pNewList;
    while(l1)
    {
        l1ToInt=l1ToInt+i*l1->val;
        l1=l1->next;
        i*=10;
    }
    i=1;
    while(l2)
    {
        l2ToInt=l2ToInt+i*l2->val;
        l2=l2->next;
        i*=10;
    }
    sum=l1ToInt+l2ToInt;
    if(sum==0)
    {
        struct ListNode*pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        if(pNode==NULL)
            return NULL;
        pNode->val=sum%10;
        pNode->next=NULL;
        pTemp->next=pNode;
        pTemp=pNode;
        return pNewList->next;
    }
    while(sum>0)
    {
        struct ListNode*pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        if(pNode==NULL)
            return NULL;

        pNode->val=sum%10;
        pNode->next=NULL;
        pTemp->next=pNode;
        pTemp=pNode;
        sum/=10;
    }
    return pNewList->next;
}
第二个思路是将两个链表各个对应结点之数相加，要考虑进位的问题，放入新链表当中。要注意的是对于数字0的处理，不能只是如下判断
if(l1->val==0)
    return l2;
if(l2->val==0)
    return l1;
这种判断会导致提交失败，因为会测试例如:输入[0123456][123123] 结果返回[123123]，导致错误。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 #include<stdlib.h>
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    int count=0;//用于进位
    int sum=0;//两数相加
    struct ListNode *pNewList=(struct ListNode*)malloc(sizeof(struct ListNode));
    pNewList->val=-1;
    pNewList->next=NULL;
    struct ListNode *pTempList=pNewList;
    while(l1&&l2)//两个链表都不为空
    {
        sum=l1->val+l2->val+count;
        if(sum>9)
        {
            sum%=10;
            count=1;
        }
        else
        {
            count=0;
        }
        struct ListNode*pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        pNode->val=sum;
        pNode->next=NULL;
        pTempList->next=pNode;
        pTempList=pNode;

        l1=l1->next;
        l2=l2->next;
    }
    while(l1)//l1链表长度大于l2链表长度
    {
        sum=l1->val+count;
        if(sum>9)
        {
            sum%=10;
            count=1;
        }
        else
        {
            count=0;
        }
        struct ListNode*pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        pNode->val=sum;
        pNode->next=NULL;
        pTempList->next=pNode;
        pTempList=pNode;
        l1=l1->next;
    }
    while(l2)//l2链表长度大于l1链表长度
    {
        sum=l2->val+count;
        if(sum>9)
        {
            sum%=10;
            count=1;
        }
        else
        {
            count=0;
        }
        struct ListNode*pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        pNode->val=sum;
        pNode->next=NULL;
        pTempList->next=pNode;
        pTempList=pNode;
        l2=l2->next;
    }
    if(count)//最后进位1需要创建一个节点存储
    {
        struct ListNode*pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        pNode->val=count;
        pNode->next=NULL;
        pTempList->next=pNode;
        pTempList=pTempList->next;
    }

    return pNewList->next;
}
```