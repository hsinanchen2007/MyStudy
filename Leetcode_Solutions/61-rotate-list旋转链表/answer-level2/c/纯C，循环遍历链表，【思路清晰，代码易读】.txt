### 解题思路
方法二：循环遍历,修改原链表
1,循环遍历一遍，算出节点个数n，
2,根据 n 和 k 找到需要旋转的位置，修改输出链表

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//方法二：循环遍历,修改原链表
//1,循环遍历一遍，算出节点个数n，
//2,根据 n 和 k 找到需要旋转的位置，修改输出链表
struct ListNode* rotateRight(struct ListNode* head, int k){
    int     i       = 0;
    int     n       = 0;
    int     iTmp    = 0;
    struct ListNode*    pHead       = head;
    struct ListNode*    pTail       = head;
    struct ListNode*    pTmp        = head;

    if (NULL == head) return NULL;

    //1, 循环遍历输入链表，算出节点个数 n，并且将输入链表复制到输出链表中
    while (NULL != pTmp)
    {
        pTail = pTmp;
        n += 1;
        pTmp = pTmp->next;
    }

    //2,根据 n 和 k 找到需要旋转的位置
    iTmp = k % n;
    pTmp = pHead;
    for (i = 1; i < n - iTmp; i++)
    {
        pTmp = pTmp->next;
    }

    //3,修改链表
    pTail->next = pHead;
    pHead = pTmp->next;
    pTmp->next = NULL;

    return pHead;
}

/*
//方法一：循环遍历,新建了一个链表
//1,循环遍历一遍，算出节点个数n，并且将输入链表复制到输出链表中
//2,根据 n 和 k 找到需要旋转的位置，修改输出链表
struct ListNode* rotateRight(struct ListNode* head, int k){
    int     i       = 0;
    int     n       = 0;
    int     iTmp    = 0;
    struct ListNode*    pHead       = NULL;
    struct ListNode*    pTail       = NULL;
    struct ListNode*    pTmpA       = head;
    struct ListNode*    pTmpB       = NULL;

    if (NULL == head) return NULL;

    pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    memset(pHead, 0x00, sizeof(struct ListNode));
    pTmpB = pHead;

    //1, 循环遍历输入链表，算出节点个数 n，并且将输入链表复制到输出链表中
    while (NULL != pTmpA)
    {
        pTmpB->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        pTmpB = pTmpB->next;
        pTmpB->val = pTmpA->val;
        pTmpB->next = NULL;
        pTail = pTmpB;
        
        n += 1;
        pTmpA = pTmpA->next;
    }

//    printf("[1][head=%d][tail=%d][n=%d][k=%d]\n", pHead->val, pTail->val, n, k);

    //2,根据 n 和 k 找到需要旋转的位置，修改输出链表
    iTmp = k % n;
    pTmpB = pHead->next;
    for (i = 1; i < n - iTmp; i++)
    {
        pTmpB = pTmpB->next;
    }

    pTail->next = pHead->next;
    pHead->next = pTmpB->next;
    pTmpB->next = NULL;

    return pHead->next;
}
*/
```