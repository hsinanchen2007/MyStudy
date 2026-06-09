### 解题思路
方法一：循环链表指针操作
方法二：递归处理
    1，确定递归终止条件
    2，实现两个节点的交换操作
    3，递归函数的应用

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//方法二：递归操作
struct ListNode* swapPairs(struct ListNode* head){

    struct ListNode*    pTmpNode    = NULL;
    //1，递归终止条件
    if ((NULL == head) || (NULL == head->next))
    {
        return head;
    }
    else
    {
        //2，交换操作
        pTmpNode = head->next;
        head->next = pTmpNode->next;
        pTmpNode->next = head;
        head = pTmpNode;

        //3，递归函数
        head->next->next = swapPairs(head->next->next);
        return head;
    }
    
}

/*
//方法一：循环链表指针操作
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
*/
```