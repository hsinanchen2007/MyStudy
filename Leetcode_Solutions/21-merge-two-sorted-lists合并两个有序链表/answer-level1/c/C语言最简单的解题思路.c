我觉得我的解题方法最简单了
1、把两个链表组合起来
2、用冒泡排序把新的链表排序。

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *pMerge = NULL;
    
    if(l1 == NULL) {
        return l2;
    }
    if(l2 == NULL) {
        return l1;
    }
    
    pMerge = l1;
    while(l1->next != NULL)
    {
        l1 = l1->next;
    }
    l1->next = l2;
    
    struct ListNode* pNode1 = pMerge;
    struct ListNode* pNode2 = pMerge;
    
    if(pMerge == NULL)
        return NULL;
    for(;pNode1->next!=NULL;pNode1=pNode1->next)
    {
        for(pNode2=pMerge;pNode2->next!=NULL;pNode2=pNode2->next)
        {
            if(pNode2->val>pNode2->next->val)
            {
                int temp = pNode2->val;
                pNode2->val = pNode2->next->val;
                pNode2->next->val = temp;
            }
        }
    }
    
    return pMerge;
}


```
