### 解题思路
此处撰写解题思路
类似归并排序
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    struct ListNode *NewList=(struct ListNode*)malloc(sizeof(struct ListNode));
    if(NewList==NULL)
        return NULL;
    struct ListNode  *plist=NewList;  
    while(l1&&l2)
    {
        if(l1->val<=l2->val)
        {
            struct ListNode *pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
            if(pNode==NULL)
                return NULL;
            pNode->val=l1->val;
            pNode->next=NULL;
            plist->next=pNode;
            plist=pNode;
            l1=l1->next;
        }
        else if(l1->val>l2->val)
        {
             struct ListNode *pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
            if(pNode==NULL)
                return NULL;
            pNode->val=l2->val;
            pNode->next=NULL;
            plist->next=pNode;
            plist=pNode;
            l2=l2->next;

        }
    }
    while(l1)
    {
        struct ListNode *pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        if(pNode==NULL)
            return NULL;
        pNode->val=l1->val;
        pNode->next=NULL;
        plist->next=pNode;
        plist=pNode;
        l1=l1->next;
    }
    while(l2)
    {
        struct ListNode *pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        if(pNode==NULL)
            return NULL;
        pNode->val=l2->val;
        pNode->next=NULL;
        plist->next=pNode;
        plist=pNode;
        l2=l2->next;
    }

    return NewList->next;

}
```