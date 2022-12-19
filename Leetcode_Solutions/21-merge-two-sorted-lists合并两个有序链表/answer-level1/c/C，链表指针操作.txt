### 解题思路
1，创建链表头
2，双链表，双指针判断
3，定位，找到需要插入的位置，注意组合链表的形成
4， l1链表节点数大于l2链表节点数，将l1插入l2中
5，链表尾部处理
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
    struct ListNode*    pTmpNode    = NULL;
    struct ListNode*    pNodel1     = NULL;
    struct ListNode*    pNodel2     = NULL;
    struct ListNode*    pHeadNode   = NULL;
    struct ListNode*    pNextNode   = NULL;

    //1，创建链表头
    pHeadNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    pHeadNode->next = NULL;
    pNextNode = pHeadNode;

    pNodel1 = l1;
    pNodel2 = l2;

    while((NULL != pNodel1) && (NULL != pNodel2))
    {
        //2，双链表，双指针判断
        if (pNodel1->val >= pNodel2->val)
        {
            if ((pNodel2->next != NULL) && (pNodel1->val >= pNodel2->next->val))
            {
                //3，定位，找到需要插入的位置，注意组合链表的形成
                pNextNode->next = pNodel2;
                pNextNode = pNodel2;
                pNodel2 = pNodel2->next;
            }
            else
            {
                //4， l1链表节点数大于l2链表节点数，将l1插入l2中
//                printf("[1] l1=%d, l2=%d, next=%d\n", pNodel1->val, pNodel2->val, pNextNode->val);
                pNextNode->next = pNodel2;

                pTmpNode = pNodel1;
                pNodel1 = pNodel1->next;

                pTmpNode->next = pNodel2->next;
                pNodel2->next = pTmpNode;

                pNodel2 = pTmpNode->next;
                pNextNode = pTmpNode;
            }
        }
        else
        {
            if ((pNodel1->next != NULL) && (pNodel2->val > pNodel1->next->val))
            {
                //3，定位，找到需要插入的位置，注意组合链表的形成
                pNextNode->next = pNodel1;
                pNextNode = pNodel1;
                pNodel1 = pNodel1->next;
            }
            else
            {
                //4， l1链表节点数小于l2链表节点数，将l2插入l1中
//                printf("[2] l1=%d, l2=%d, next=%d\n", pNodel1->val, pNodel2->val, pNextNode->val);
                pNextNode->next = pNodel1;

                pTmpNode = pNodel2;
                pNodel2 = pNodel2->next;
                
                pTmpNode->next = pNodel1->next;
                pNodel1->next = pTmpNode;

                pNodel1 = pTmpNode->next;
                pNextNode = pTmpNode;
            }
        }
    }

    //5，链表尾部处理
    if (NULL != pNodel1)
    {
        pNextNode->next = pNodel1;
    }

    if (NULL != pNodel2)
    {
        pNextNode->next = pNodel2;
    }

    return pHeadNode->next;
}
```