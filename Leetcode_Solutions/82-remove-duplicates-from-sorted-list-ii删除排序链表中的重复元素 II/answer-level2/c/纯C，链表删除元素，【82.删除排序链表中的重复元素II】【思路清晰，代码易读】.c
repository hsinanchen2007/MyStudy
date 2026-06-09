### 解题思路
方法一：链表删除元素

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//方法一：链表删除元素
struct ListNode* deleteDuplicates(struct ListNode* head){
    bool    bFlag   = false;
    struct ListNode*    pHead       = NULL;
    struct ListNode*    pHeadNode   = NULL;
    struct ListNode*    pCurNode    = NULL;
    struct ListNode*    pNextNode   = NULL;

    if (NULL == head) return NULL;

    pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    pHead->next = head;
    pHead->val = head->val;

    pHeadNode = pHead;
    pCurNode = head;
    pNextNode = pCurNode->next;
    while(pNextNode != NULL)
    {
        if(pCurNode->val == pNextNode->val)
        {
            pNextNode = pNextNode->next;
            pCurNode->next = pNextNode;
            bFlag = true;
        }
        else
        {
            if(bFlag)
            {
                bFlag = false;
                pHeadNode->next = pCurNode->next;
                pCurNode = pNextNode;
            }
            else
            {
                pHeadNode = pCurNode;
                pCurNode = pNextNode;
            }
        }
        pNextNode = pCurNode->next;
    }
    if (bFlag)
    {
        pHeadNode->next = pCurNode->next;
    }
    return pHead->next;
}
```