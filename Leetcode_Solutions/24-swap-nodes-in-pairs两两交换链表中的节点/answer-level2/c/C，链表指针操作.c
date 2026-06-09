### 解题思路
链表指针操作
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode*    pTmpNode   = NULL;
    struct ListNode*    pTmpNode1   = NULL;
    struct ListNode*    pTmpNode2   = NULL;
    struct ListNode*    pHeadNode   = NULL;
    
    pHeadNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    pHeadNode->next = head;
    pTmpNode = pHeadNode;
    pTmpNode1 = pHeadNode->next;

    while(NULL != pTmpNode1)
    {
        pTmpNode2 = pTmpNode1->next;

        if (NULL != pTmpNode2)
        {
            pTmpNode->next = pTmpNode2;
            pTmpNode1->next = pTmpNode2->next;
            pTmpNode2->next = pTmpNode1;
        }

        pTmpNode = pTmpNode1;
        pTmpNode1 = pTmpNode1->next;
    }
    return pHeadNode->next;
}
```