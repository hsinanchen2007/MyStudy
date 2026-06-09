### 解题思路
合并两个链表方法：
    方法一：递归法
    方法二：双链表，双指针操作  指针操作比递归法要快

合并多个链表的方法：
    方法一：循环处理，循环n-1次将所有链表分解为两个链表的合并
    方法二：分治法，将多个链表逐个分段处理，要比方法一少处理很多次

方法二结合方法二速度最快
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
//方法一：递归处理两个链表的合并
struct ListNode* mergeTwoList(struct ListNode* l1, struct ListNode* l2){
    //1，递归结束条件
    if (NULL == l1)
    {
        return l2;
    }
    if (NULL == l2)
    {
        return l1;
    }

    //2，递归条件
    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoList(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoList(l1, l2->next);
        return l2;
    }
}
*/

//方法2：双链表，双指针操作 处理两个链表合并
struct ListNode* mergeTwoList(struct ListNode* l1, struct ListNode* l2){
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


//方法二：有点回溯法的意思
struct ListNode* mergeKListsHandle(struct ListNode** lists, int listsSize){
    int     iCount      = 0;
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    iCount = listsSize;

    if (iCount == 0)
    {
        return NULL;
    }
    else if (iCount == 1)
    {
        return lists[0];
    }
    else if (iCount == 2)
    {
        return mergeTwoList(lists[0], lists[1]);
    }

    l1 = mergeKListsHandle(&lists[0], (iCount + 1) / 2);
    l2 = mergeKListsHandle(&lists[(iCount + 1) / 2], iCount - (iCount + 1) / 2);

    return mergeTwoList(l1, l2);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    return mergeKListsHandle(lists, listsSize);
}


/*
//方法一：循环递归
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int     i   = 0;

    struct ListNode* pHeadNode = NULL;

    if ((NULL == lists) || (0 == listsSize))
    {
        return NULL;
    }

    pHeadNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    pHeadNode->next = lists[0];

    for (i = 1; i < listsSize; i++)
    {
        pHeadNode->next = mergeTwoList(pHeadNode->next, lists[i]);
    }
    
    return pHeadNode->next;
}
*/
```