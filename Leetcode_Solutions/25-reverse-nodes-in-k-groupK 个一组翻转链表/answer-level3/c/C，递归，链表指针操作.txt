### 解题思路
分解为两部分处理：
第一部分，翻转链表的k个节点，循环k次将后面的节点依次翻转到链表头
第二部分，递归处理整个链表，
    1，判断结束返回条件
    2，调用子函数实现k个节点的翻转
    3，递归的方法，用上一个k链表最后一个元素的nex做递归处理衔接
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//将链表中k个节点进行翻转
struct ListNode* reverseK(struct ListNode* head, int k){
    int     i       = 0;

    struct ListNode* pTmpNode    = NULL;
    struct ListNode* pHeadNode   = NULL;
    struct ListNode* pNextNode   = NULL;

    pTmpNode = head;
    pHeadNode = head;       //指向链表的第一个节点，翻转完之后指向地k个节点

    pNextNode = head->next;
    for (i = 1; i < k; i++)
    {
        pTmpNode = pNextNode;
        pNextNode = pNextNode->next;

        pHeadNode->next = pTmpNode->next;
        pTmpNode->next = head;
        head = pTmpNode;
    }
    return head;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int     i       = 0;
    struct ListNode*    pTmpNode    = NULL;
    struct ListNode*    pKNode      = NULL;

    //1，结束调条件
    pTmpNode = head;
    for (i = 0; i < k; i++)
    {
        if (NULL == pTmpNode)
        {
            // 如果链表不足K个节点，则保持原有顺序不变
            return head;
        }
        else
        {
            pTmpNode = pTmpNode->next;
        }
    }
    pKNode = head;                  // pKNode 指向传入链表的第一个元素

    //2，k个节点的翻转
    head = reverseK(head, k);       // 经过翻转后 pKNode=head 指向翻转k后最后一个元素

    //3，递归的方法，用上一个k链表最后一个元素的nex做递归处理衔接
    pKNode->next = reverseKGroup(pKNode->next, k);

    return head;
}
```